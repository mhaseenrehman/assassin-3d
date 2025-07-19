#pragma once

// DirectX11 Header Files
#include "d3d11.h"
#include "d3d12.h"
#include "..\d3d12-proxy\WrappedD3D12Device.h"
#include "d3dtypes.h"
#include <string>

//------------------------------------------------------------------------------------------------
// 
//											HASHASHIN HACKS
// 
// Typedefs - For each input assembly and a map of all the input assemblies
// For each draw call, you have an input assembler stage; Vertex and index buffers are apart of 
// this stage. Input layout objects: includes a description of the input data bound to the IA stage
// D3D11_INPUT_ELEMENT_DESC is a type that contains a single input element description
// Each input element describes a single vertex data element from a single vertex buffer
// Data enters the IA stage through input slots, there can be n input slots therefore n vertex 
// buffers. Information is stored in the input layout declaration when the input layout object is
// created. Can specify an offset from the start of each buffer to the first element in the buffer to
// be read. Input slot = where, Input offset = number of bytes between start of buffer and first
// element.
// 
// Summary: 
// Input Layout Object -> Array of Input Element Description = Desc of single vertex element
// Each vertex buffer has a different input slot -> MUST store this when call IAGetVertexBuffer 
// 
// Ninja Ripper hooks the createInputLayout function in DirectX to statically retrieve all the input
// layouts beforehand 
// Single element descriptor for a single vertex data element in a single vertex buffer
// 
// Example:
// 
// D3D11_INPUT_ELEMENT_DESC layout[] =
// {
//    { L"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, 
//          D3D11_INPUT_PER_VERTEX_DATA, 0 },
//    { L"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, 
//          D3D11_INPUT_PER_VERTEX_DATA, 0 },
//    { L"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 20, 
//          D3D11_INPUT_PER_VERTEX_DATA, 0 },
//};
//{ L"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 } = D3D11_INPUT_ELEMENT_DESC. This type = hookedD3D11InputElementDesc
// 
//------------------------------------------------------------------------------------------------
struct OrigD3D11InputElementDesc {
	char					   SemanticName[64];
	UINT                       SemanticIndex;
	DXGI_FORMAT                Format;
	UINT                       InputSlot;
	UINT                       AlignedByteOffset;
	D3D11_INPUT_CLASSIFICATION InputSlotClass;
	UINT                       InstanceDataStepRate;
};

// Each Input Layout has many Input Element Descriptions or in this case: hookedD3D11InputElementDesc's
typedef std::vector<OrigD3D11InputElementDesc> OrigD3D11VertexDeclaration;

// Data map for all the input layouts of the entire scene - so we don't rip models twice
typedef std::map<ID3D11InputLayout*, OrigD3D11VertexDeclaration> InputAssemblyDataMap;

// Input Vertex Elements - Specifies Element description for original vertex buffer
struct InputD3D11VertexElement {
	char						UsageSemantic[64];
	DWORD                       SemanticIndex;
	DWORD                       InputSlot;
	DWORD                       Offset;
	DWORD						Size;
	DXGI_FORMAT					Type;
};

struct InputVertexDeclaration {
	std::vector<InputD3D11VertexElement> declaration;
};

// Output Vertex Declaration - Similar to D3D11_INPUT_ELEMENT_DESC but it's for the VERTICES array instead
struct OutputD3D11VertexElement {
	char						UsageSemantic[64];
	DWORD                       SemanticIndex;
	DWORD                       Offset;
	DWORD						Size;
	DXGI_FORMAT					Type;


};

struct OutputVertexDeclaration {
	std::vector<OutputD3D11VertexElement> declaration;
};

// Important structure for when we convert to .OBJ
// We need to extract the POSITION and NORMAL from the Vertex Buffers
// Craft faces from the index buffers
struct VERTICES {
	DWORD VertexCount;
	DWORD VertexSize;
	BYTE* pVertices;

	VERTICES(DWORD VertexCount_, DWORD VertexSize_) : VertexCount(VertexCount_), VertexSize(VertexSize_){
		pVertices = new BYTE[VertexCount * VertexSize];
	}

	~VERTICES() {
		SAFE_DELETE_ARRAY(pVertices);
	}

};

struct Face {
	DWORD v_1;
	DWORD v_2;
	DWORD v_3;
};

struct FACES {
	DWORD primitiveCount;
	DWORD minIndex;
	DWORD maxIndex;
	
	Face* pFaces;

	FACES(DWORD primCount_) : primitiveCount(primCount_), minIndex(0), maxIndex(0), pFaces(NULL){
		pFaces = new (std::nothrow) Face[primCount_];
	}

	~FACES() {
		SAFE_DELETE_ARRAY(pFaces);
	}

	DWORD getVertexCount() {
		return 1 + maxIndex + minIndex;
	}
};



// Input assembly database
class VertexInputAssemblies {
public:
	InputAssemblyDataMap vertexInputStore;
	
public:
	void addInputAssembly(ID3D11InputLayout* ppInputLayout, OrigD3D11VertexDeclaration inputElements);
	UINT getInputAssembly(ID3D11InputLayout* currentInputLayout, OrigD3D11VertexDeclaration& elements);
};

//------------------------------------------------------------------------------------------------
// 
//											BASE DX11 HOOK
// 
//------------------------------------------------------------------------------------------------

bool DUMP1 = false;
bool DUMP2 = false;

typedef HRESULT(WINAPI* D3D11_Core_Create_Device)(IDXGIFactory* pFactory, IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, UINT SDKVersion, ID3D11Device** ppDevice, D3D_FEATURE_LEVEL* pFeatureLevel);
typedef HRESULT(WINAPI* D3D11_Create_Device)(IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, UINT SDKVersion, ID3D11Device** ppDevice, D3D_FEATURE_LEVEL* pFeatureLevel, ID3D11DeviceContext** ppImmediateContext);
typedef HRESULT(WINAPI* D3D11_On_12_Create_Device)(IUnknown* pDevice, UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, IUnknown* const* ppCommandQueues, UINT NumQueues, UINT NodeMask, ID3D11Device** ppDevice, ID3D11DeviceContext** ppImmediateContext, D3D_FEATURE_LEVEL* pChosenFeatureLevel);
typedef HRESULT(WINAPI* D3D11_Create_Device_And_Swap_Chain)(IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, UINT SDKVersion, const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc, IDXGISwapChain** ppSwapChain, ID3D11Device** ppDevice, D3D_FEATURE_LEVEL* pFeatureLevel, ID3D11DeviceContext** ppImmediateContext);

HRESULT WINAPI D3D11On12CreateDevice(IUnknown* pDevice, UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, IUnknown* const* ppCommandQueues, UINT NumQueues, UINT NodeMask, ID3D11Device** ppDevice, ID3D11DeviceContext** ppImmediateContext, D3D_FEATURE_LEVEL* pChosenFeatureLevel);

BOOL DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved);


//------------------------------------------------------------------------------------------------
// 
//											DEBUG LOGGER
// 
//		Required for purely debugging purposes - Print out elements and D3D11 types to screen
// 
//------------------------------------------------------------------------------------------------

class DebugLogger {
public:
	static void print_input_element_description(OrigD3D11InputElementDesc desc);
	static void print_input_layout();
};