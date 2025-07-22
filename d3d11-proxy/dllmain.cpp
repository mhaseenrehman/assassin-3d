//------------------------------------------------------------------------------------------------
//
//		IMPORTS & DEFINITIONS - dllmain.cpp : Defines the entry point for the DLL application.
//
//------------------------------------------------------------------------------------------------
#include "pch.h"
#include "dllmain.h"

//#define CREATE_DX12
#define _CRT_SECURE_NO_DEPRECATE

#pragma warning (disable : 4996)

HMODULE originalD3D11 = NULL;
#pragma region  handles

D3D11_Core_Create_Device coreCreateDevice;
D3D11_Create_Device createDevice;
D3D11_Create_Device_And_Swap_Chain createDeviceAndSwapChain;
D3D11_On_12_Create_Device d3d11on12CreateDevice;

FARPROC D3D11CreateDeviceForD3D12Org;
FARPROC D3DKMTCloseAdapterOrg;
FARPROC D3DKMTDestroyAllocationOrg;
FARPROC D3DKMTDestroyContextOrg;
FARPROC D3DKMTDestroyDeviceOrg;
FARPROC D3DKMTDestroySynchronizationObjectOrg;
FARPROC D3DKMTPresentOrg;
FARPROC D3DKMTQueryAdapterInfoOrg;
FARPROC D3DKMTSetDisplayPrivateDriverFormatOrg;
FARPROC D3DKMTSignalSynchronizationObjectOrg;
FARPROC D3DKMTUnlockOrg;
FARPROC D3DKMTWaitForSynchronizationObjectOrg;
FARPROC EnableFeatureLevelUpgradeOrg;
FARPROC OpenAdapter10Org;
FARPROC OpenAdapter10_2Org;
FARPROC CreateDirect3D11DeviceFromDXGIDeviceOrg;
FARPROC CreateDirect3D11SurfaceFromDXGISurfaceOrg;
FARPROC D3D11CoreCreateLayeredDeviceOrg;
FARPROC D3D11CoreGetLayeredDeviceSizeOrg;
FARPROC D3D11CoreRegisterLayersOrg;
FARPROC D3DKMTCreateAllocationOrg;
FARPROC D3DKMTCreateContextOrg;
FARPROC D3DKMTCreateDeviceOrg;
FARPROC D3DKMTCreateSynchronizationObjectOrg;
FARPROC D3DKMTEscapeOrg;
FARPROC D3DKMTGetContextSchedulingPriorityOrg;
FARPROC D3DKMTGetDeviceStateOrg;
FARPROC D3DKMTGetDisplayModeListOrg;
FARPROC D3DKMTGetMultisampleMethodListOrg;
FARPROC D3DKMTGetRuntimeDataOrg;
FARPROC D3DKMTGetSharedPrimaryHandleOrg;
FARPROC D3DKMTLockOrg;
FARPROC D3DKMTOpenAdapterFromHdcOrg;
FARPROC D3DKMTOpenResourceOrg;
FARPROC D3DKMTQueryAllocationResidencyOrg;
FARPROC D3DKMTQueryResourceInfoOrg;
FARPROC D3DKMTRenderOrg;
FARPROC D3DKMTSetAllocationPriorityOrg;
FARPROC D3DKMTSetContextSchedulingPriorityOrg;
FARPROC D3DKMTSetDisplayModeOrg;
FARPROC D3DKMTSetGammaRampOrg;
FARPROC D3DKMTSetVidPnSourceOwnerOrg;
FARPROC D3DKMTWaitForVerticalBlankEventOrg;
FARPROC D3DPerformance_BeginEventOrg;
FARPROC D3DPerformance_EndEventOrg;
FARPROC D3DPerformance_GetStatusOrg;
FARPROC D3DPerformance_SetMarkerOrg;

extern FARPROC D3D11CreateDeviceForD3D12Org;
extern FARPROC D3DKMTCloseAdapterOrg;
extern FARPROC D3DKMTDestroyAllocationOrg;
extern FARPROC D3DKMTDestroyContextOrg;
extern FARPROC D3DKMTDestroyDeviceOrg;
extern FARPROC D3DKMTDestroySynchronizationObjectOrg;
extern FARPROC D3DKMTPresentOrg;
extern FARPROC D3DKMTQueryAdapterInfoOrg;
extern FARPROC D3DKMTSetDisplayPrivateDriverFormatOrg;
extern FARPROC D3DKMTSignalSynchronizationObjectOrg;
extern FARPROC D3DKMTUnlockOrg;
extern FARPROC D3DKMTWaitForSynchronizationObjectOrg;
extern FARPROC EnableFeatureLevelUpgradeOrg;
extern FARPROC OpenAdapter10Org;
extern FARPROC OpenAdapter10_2Org;
extern FARPROC CreateDirect3D11DeviceFromDXGIDeviceOrg;
extern FARPROC CreateDirect3D11SurfaceFromDXGISurfaceOrg;
extern FARPROC D3D11CoreCreateLayeredDeviceOrg;
extern FARPROC D3D11CoreGetLayeredDeviceSizeOrg;
extern FARPROC D3D11CoreRegisterLayersOrg;
extern FARPROC D3DKMTCreateAllocationOrg;
extern FARPROC D3DKMTCreateContextOrg;
extern FARPROC D3DKMTCreateDeviceOrg;
extern FARPROC D3DKMTCreateSynchronizationObjectOrg;
extern FARPROC D3DKMTEscapeOrg;
extern FARPROC D3DKMTGetContextSchedulingPriorityOrg;
extern FARPROC D3DKMTGetDeviceStateOrg;
extern FARPROC D3DKMTGetDisplayModeListOrg;
extern FARPROC D3DKMTGetMultisampleMethodListOrg;
extern FARPROC D3DKMTGetRuntimeDataOrg;
extern FARPROC D3DKMTGetSharedPrimaryHandleOrg;
extern FARPROC D3DKMTLockOrg;
extern FARPROC D3DKMTOpenAdapterFromHdcOrg;
extern FARPROC D3DKMTOpenResourceOrg;
extern FARPROC D3DKMTQueryAllocationResidencyOrg;
extern FARPROC D3DKMTQueryResourceInfoOrg;
extern FARPROC D3DKMTRenderOrg;
extern FARPROC D3DKMTSetAllocationPriorityOrg;
extern FARPROC D3DKMTSetContextSchedulingPriorityOrg;
extern FARPROC D3DKMTSetDisplayModeOrg;
extern FARPROC D3DKMTSetGammaRampOrg;
extern FARPROC D3DKMTSetVidPnSourceOwnerOrg;
extern FARPROC D3DKMTWaitForVerticalBlankEventOrg;
extern FARPROC D3DPerformance_BeginEventOrg;
extern FARPROC D3DPerformance_EndEventOrg;
extern FARPROC D3DPerformance_GetStatusOrg;
extern FARPROC D3DPerformance_SetMarkerOrg;

#pragma endregion

extern "C" void Proxy_CallOrgFcnAsm(void);
extern "C" FARPROC FcnPtrOrg = NULL;
extern "C" {
	void D3D11CreateDeviceForD3D12() { FcnPtrOrg = D3D11CreateDeviceForD3D12Org; Proxy_CallOrgFcnAsm(); }
	void D3DKMTCloseAdapter() { FcnPtrOrg = D3DKMTCloseAdapterOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTDestroyAllocation() { FcnPtrOrg = D3DKMTDestroyAllocationOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTDestroyContext() { FcnPtrOrg = D3DKMTDestroyContextOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTDestroyDevice() { FcnPtrOrg = D3DKMTDestroyDeviceOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTDestroySynchronizationObject() { FcnPtrOrg = D3DKMTDestroySynchronizationObjectOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTPresent() { FcnPtrOrg = D3DKMTPresentOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTQueryAdapterInfo() { FcnPtrOrg = D3DKMTQueryAdapterInfoOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTSetDisplayPrivateDriverFormat() { FcnPtrOrg = D3DKMTSetDisplayPrivateDriverFormatOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTSignalSynchronizationObject() { FcnPtrOrg = D3DKMTSignalSynchronizationObjectOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTUnlock() { FcnPtrOrg = D3DKMTUnlockOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTWaitForSynchronizationObject() { FcnPtrOrg = D3DKMTWaitForSynchronizationObjectOrg; Proxy_CallOrgFcnAsm(); }
	void EnableFeatureLevelUpgrade() { FcnPtrOrg = EnableFeatureLevelUpgradeOrg; Proxy_CallOrgFcnAsm(); }
	void OpenAdapter10() { FcnPtrOrg = OpenAdapter10Org; Proxy_CallOrgFcnAsm(); }
	void OpenAdapter10_2() { FcnPtrOrg = OpenAdapter10_2Org; Proxy_CallOrgFcnAsm(); }
	void CreateDirect3D11DeviceFromDXGIDevice() { FcnPtrOrg = CreateDirect3D11DeviceFromDXGIDeviceOrg; Proxy_CallOrgFcnAsm(); }
	void CreateDirect3D11SurfaceFromDXGISurface() { FcnPtrOrg = CreateDirect3D11SurfaceFromDXGISurfaceOrg; Proxy_CallOrgFcnAsm(); }
	void D3D11CoreCreateLayeredDevice() { FcnPtrOrg = D3D11CoreCreateLayeredDeviceOrg; Proxy_CallOrgFcnAsm(); }
	void D3D11CoreGetLayeredDeviceSize() { FcnPtrOrg = D3D11CoreGetLayeredDeviceSizeOrg; Proxy_CallOrgFcnAsm(); }
	void D3D11CoreRegisterLayers() { FcnPtrOrg = D3D11CoreRegisterLayersOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTCreateAllocation() { FcnPtrOrg = D3DKMTCreateAllocationOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTCreateContext() { FcnPtrOrg = D3DKMTCreateContextOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTCreateDevice() { FcnPtrOrg = D3DKMTCreateDeviceOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTCreateSynchronizationObject() { FcnPtrOrg = D3DKMTCreateSynchronizationObjectOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTEscape() { FcnPtrOrg = D3DKMTEscapeOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTGetContextSchedulingPriority() { FcnPtrOrg = D3DKMTGetContextSchedulingPriorityOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTGetDeviceState() { FcnPtrOrg = D3DKMTGetDeviceStateOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTGetDisplayModeList() { FcnPtrOrg = D3DKMTGetDisplayModeListOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTGetMultisampleMethodList() { FcnPtrOrg = D3DKMTGetMultisampleMethodListOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTGetRuntimeData() { FcnPtrOrg = D3DKMTGetRuntimeDataOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTGetSharedPrimaryHandle() { FcnPtrOrg = D3DKMTGetSharedPrimaryHandleOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTLock() { FcnPtrOrg = D3DKMTLockOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTOpenAdapterFromHdc() { FcnPtrOrg = D3DKMTOpenAdapterFromHdcOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTOpenResource() { FcnPtrOrg = D3DKMTOpenResourceOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTQueryAllocationResidency() { FcnPtrOrg = D3DKMTQueryAllocationResidencyOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTQueryResourceInfo() { FcnPtrOrg = D3DKMTQueryResourceInfoOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTRender() { FcnPtrOrg = D3DKMTRenderOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTSetAllocationPriority() { FcnPtrOrg = D3DKMTSetAllocationPriorityOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTSetContextSchedulingPriority() { FcnPtrOrg = D3DKMTSetContextSchedulingPriorityOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTSetDisplayMode() { FcnPtrOrg = D3DKMTSetDisplayModeOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTSetGammaRamp() { FcnPtrOrg = D3DKMTSetGammaRampOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTSetVidPnSourceOwner() { FcnPtrOrg = D3DKMTSetVidPnSourceOwnerOrg; Proxy_CallOrgFcnAsm(); }
	void D3DKMTWaitForVerticalBlankEvent() { FcnPtrOrg = D3DKMTWaitForVerticalBlankEventOrg; Proxy_CallOrgFcnAsm(); }
	void D3DPerformance_BeginEvent() { FcnPtrOrg = D3DPerformance_BeginEventOrg; Proxy_CallOrgFcnAsm(); }
	void D3DPerformance_EndEvent() { FcnPtrOrg = D3DPerformance_EndEventOrg; Proxy_CallOrgFcnAsm(); }
	void D3DPerformance_GetStatus() { FcnPtrOrg = D3DPerformance_GetStatusOrg; Proxy_CallOrgFcnAsm(); }
	void D3DPerformance_SetMarker() { FcnPtrOrg = D3DPerformance_SetMarkerOrg; Proxy_CallOrgFcnAsm(); }
}

//------------------------------------------------------------------------------------------------
// 
//												GLOBALS
// 
//------------------------------------------------------------------------------------------------
HINSTANCE dll_handle;

// Original Function Pointer to Draw Functions
typedef void(__stdcall* DrawIndexed_t)(ID3D11DeviceContext* pDevice, UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation);
DrawIndexed_t pDrawIndexedDummy;
DrawIndexed_t pDrawIndexedOriginal;

typedef HRESULT(__stdcall* CreateInputLayout_t)(ID3D11Device* pDevice, const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs, UINT NumElements, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength, ID3D11InputLayout** ppInputLayout);
CreateInputLayout_t pCreateInputLayoutDummy;
CreateInputLayout_t pCreateInputLayoutOriginal;

VertexInputAssemblies sceneData;

//------------------------------------------------------------------------------------------------
// 
//											HASHASHIN HACKS
// 
//    INTERCEPT A CALL TO draw methods to access buffer contents and extract to GLTF:
//	  Draw, DrawAuto, DrawIndexed, DrawIndexedInstanced, DrawIndexedInstanced, DrawInstanced
//    DrawInstancedIndirect are all intercepted and counted
//	  
//	  Indices of Virtual methods:
//	  Draw 13
//	  DrawAuto 38
//	  DrawIndexed 12
//	  DrawIndexedInstanced 20
//	  DrawIndexedInstancedIndirect 39
//	  DrawInstanced 21
// 
//	  Vertex Obtaining Hook - Obtaining mesh from video game
//	  Step 0: Hook into drawIndexed
//	  Step 1: Get Primitives & Calculate number of primitives
//	  Step 2: Get Vertex Declarations
//	  Step 3: Dump Vertex Buffers
//    Step 4: Dump Index Buffers
//	  Step 5: Extract To OBJ File
//------------------------------------------------------------------------------------------------

//---------------------------------------- GENERAL UTILITY ---------------------------------------
HRESULT copyBuffer(ID3D11DeviceContext* pContext, ID3D11Buffer* pSrcBuffer, ID3D11Buffer** ppDestBuffer) {
	D3D11_BUFFER_DESC srcDesc;
	D3D11_BUFFER_DESC destDesc;

	ID3D11Device* pDeviceRef;
	*ppDestBuffer = NULL;

	pSrcBuffer->GetDesc(&srcDesc);

	destDesc = srcDesc;
	destDesc.Usage = D3D11_USAGE_STAGING;
	destDesc.BindFlags = 0;
	destDesc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;

	pContext->GetDevice(&pDeviceRef);

	if (!pDeviceRef->CreateBuffer(&destDesc, NULL, ppDestBuffer)) {
		return ERROR;
	}

	pContext->CopyResource(*ppDestBuffer, pSrcBuffer);

	return S_OK;
}

//-------------------------------------------- STEP 1 --------------------------------------------

HRESULT ObtainOutputVertexDeclaration(const InputVertexDeclaration &inputVertexDeclaration, OutputVertexDeclaration &outputVertexDeclaration) {
	DWORD offset = 0;

	for (size_t i = 0; i < inputVertexDeclaration.declaration.size(); i++) {
		OutputD3D11VertexElement outputElem;

		BYTE inputData[64] = { 0 };
		BYTE unpackedData[64] = { 0 };
		DWORD compCnt = 0;

		DXGI_FORMAT inputType = inputVertexDeclaration.declaration[i].Type;
		if (inputType == DXGI_FORMAT_UNKNOWN) {
			OutputDebugStringW(L"ERROR 1: Unknown DXGI format found");
			return E_FAIL;
		}

		DWORD unpackedSize = D3DTypesDatabase::decodeAndCopy(inputType, inputData, unpackedData, compCnt);
	
		strcpy(outputElem.UsageSemantic, inputVertexDeclaration.declaration[i].UsageSemantic);
		outputElem.SemanticIndex = inputVertexDeclaration.declaration[i].SemanticIndex;
		outputElem.Size = unpackedSize;
		outputElem.Offset = offset;

		outputVertexDeclaration.declaration.push_back(outputElem);
		offset += unpackedSize;
	}

	return S_OK;
}

HRESULT obtainVertexDeclarations(ID3D11DeviceContext* pContext, InputVertexDeclaration &inputVertexDeclaration, OutputVertexDeclaration &outputVertexDeclaration) {
	// First get input layout for the current draw call
	ID3D11InputLayout* currentInputLayout = NULL;
	pContext->IAGetInputLayout(&currentInputLayout);
	
	// Find this input layout in the database and obtain the Vertex Declaration that comes with it
	OrigD3D11VertexDeclaration OrigVertexDecl;
	sceneData.getInputAssembly(currentInputLayout, OrigVertexDecl);

	// Create an input vertex declaration from the Input layout and the Vertex Declarations it has
	for (size_t i = 0; i < OrigVertexDecl.size(); i++) {
		InputD3D11VertexElement inputElement;

		OrigD3D11InputElementDesc origElement = OrigVertexDecl[i];
		
		strcpy(inputElement.UsageSemantic, origElement.SemanticName);
		inputElement.SemanticIndex = origElement.SemanticIndex;
		inputElement.InputSlot = origElement.InputSlot;
		inputElement.Offset = origElement.AlignedByteOffset;
		inputElement.Type = origElement.Format;
		inputElement.Size = D3DTypesDatabase::dp_obtainTypeSize(inputElement.Type);
		
		// Add to input Vertex Declaration
		inputVertexDeclaration.declaration.push_back(inputElement);
	}

	// Find all the possible inputs slots for each Vertex Declaration
	// There can be up to n different slots for each vertex buffer at input assembly stage
	// Find all the slots and therefore, all the vertex buffers
	std::vector<DWORD> uniqueSlots;
	for (size_t i = 0; i < OrigVertexDecl.size(); i++) {
		DWORD inputSlot = inputVertexDeclaration.declaration[i].InputSlot;
		BOOL slotFound = FALSE;
		for (size_t j = 0; j < uniqueSlots.size(); j++) {
			if (uniqueSlots[j] != inputSlot) {
				slotFound = TRUE;
				break;
			}
		}

		if (!slotFound) {
			uniqueSlots.push_back(inputSlot);
		}
	}

	// Obtain Correct Stream and offset numbers for each Vertex Buffer
	// Each Vertex Buffer has an offset from the beginning to each element
	for (size_t i = 0; i < uniqueSlots.size(); i++) {
		DWORD offset = 0;
		for (size_t j = 0; j < inputVertexDeclaration.declaration.size(); j++) {
			if (inputVertexDeclaration.declaration[j].InputSlot == uniqueSlots[j]) {

				// If using this, it defines the current element to be directly after the previous one in memory
				if (inputVertexDeclaration.declaration[j].Offset == D3D11_APPEND_ALIGNED_ELEMENT) {
					inputVertexDeclaration.declaration[j].Offset = offset;
				}

				offset += inputVertexDeclaration.declaration[j].Size;
			}
		}
	}

	// Create Output Vertex Declaration from the input vertex declaration
	if (ObtainOutputVertexDeclaration(inputVertexDeclaration, outputVertexDeclaration) != S_OK) {
		OutputDebugStringW(L"ERROR 1: Output Vertex Declaration not obtained");
		return E_FAIL;
	}

	return S_OK;
}

//-------------------------------------------- STEP 2 --------------------------------------------
D3D11_PRIMITIVE_TOPOLOGY obtainPrimitives(ID3D11DeviceContext* pContext) {
	D3D11_PRIMITIVE_TOPOLOGY topology = D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED;
	pContext->IAGetPrimitiveTopology(&topology);
	return topology;
}

UINT calculatePrimitiveCount(UINT indexCount, D3D11_PRIMITIVE_TOPOLOGY topology) {
	// Check topology for type - if triangle list, then there are / 3 number of objects else - 2
	if (topology == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST) {
		return (UINT)(indexCount / 3);
	}
	else if (topology == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP) {
		return (UINT)(indexCount - 2);
	}
	return 0;
}

//-------------------------------------------- STEP 3 --------------------------------------------
static DWORD checkMax(DWORD max1, DWORD maxV) {
	return (max1 > maxV) ? max1 : maxV;
}

static DWORD checkMin(DWORD min1, DWORD minV) {
	return (min1 < minV) ? min1 : minV;
}

template <class T>
static void dumpIndexesToFaces(T *pSrc, UINT bitLength, UINT StartIndexLocation, FACES* pFaces, D3D_PRIMITIVE_TOPOLOGY primitiveType) {
	// May need to change this code if pSrc keeps itself as BYTE*
	pSrc = pSrc + StartIndexLocation;

	// Maximum number of iterations
	DWORD dwPrimCount = pFaces->primitiveCount;

	DWORD maxIdx = 0;
	DWORD minIdx = 0xFFFFFFFF;

	// Obtain max indexes of faces
	T* pSrc2 = pSrc;
	if (primitiveType == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST) {
		for (DWORD i = 0; i < dwPrimCount; i++) {
			maxIdx = checkMax((T)(*pSrc2), maxIdx);
			pSrc2++;

			maxIdx = checkMax((T)(*pSrc2), maxIdx);
			pSrc2++;

			maxIdx = checkMax((T)(*pSrc2), maxIdx);
			pSrc2++;
		}
	}
	else if (primitiveType == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP) {
		DWORD clockwiseOrNot = 0;
		for (DWORD i = 0; i < dwPrimCount; i++) {
			maxIdx = checkMin((T)(*pSrc2), maxIdx);

			// Normal Order
			if (!(clockwiseOrNot & 0x0)) {
				maxIdx = checkMax((T)(*(pSrc2 + 1)), maxIdx);
				maxIdx = checkMax((T)(*(pSrc2 + 2)), maxIdx);
			}
			// Anticlockwise Order
			else {
				maxIdx = checkMax((T)(*(pSrc2 + 2)), maxIdx);
				maxIdx = checkMax((T)(*(pSrc2 + 1)), maxIdx);
			}

			clockwiseOrNot++;
			pSrc2++;
		}
	}

	// Obtain min indexes of faces
	pSrc2 = pSrc;
	if (primitiveType == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST) {
		for (DWORD i = 0; i < dwPrimCount; i++) {
			minIdx = checkMin((T)(*pSrc2), minIdx);
			pSrc2++;

			minIdx = checkMin((T)(*pSrc2), minIdx);
			pSrc2++;

			minIdx = checkMin((T)(*pSrc2), minIdx);
			pSrc2++;
		}
	}
	else if (primitiveType == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP) {
		DWORD clockwiseOrNot = 0;
		for (DWORD i = 0; i < dwPrimCount; i++) {
			minIdx = checkMin((T)(*pSrc2), minIdx);

			// Normal Order
			if (!(clockwiseOrNot & 0x0)) {
				minIdx = checkMin((T)(*(pSrc2 + 1)), minIdx);
				minIdx = checkMin((T)(*(pSrc2 + 2)), minIdx);
			}
			// Anticlockwise Order
			else {
				minIdx = checkMin((T)(*(pSrc2 + 2)), minIdx);
				minIdx = checkMin((T)(*(pSrc2 + 1)), minIdx);
			}

			clockwiseOrNot++;
			pSrc2++;
		}
	}

	pFaces->maxIndex = maxIdx;
	pFaces->minIndex = minIdx;

	// Dump indexes to face
	Face* currentFace = pFaces->pFaces;

	// Triangle lists are fairly simple - dump all sequentially
	if (primitiveType == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST) {
		for (DWORD i = 0; i < dwPrimCount; i++) {
			currentFace->v_1 = (DWORD)(*pSrc);
			pSrc++;

			currentFace->v_2 = (DWORD)(*pSrc);
			pSrc++;

			currentFace->v_3 = (DWORD)(*pSrc);
			pSrc++;

			currentFace++;
		}
	}

	// Triangle strips have alternating clockwise and anti-clockwise rotations
	// E.g.: Indexes can look like this - v1,v2,v3 or v2,v4,v3, etc. need to take order into account
	else if (primitiveType == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP) {
		DWORD clockwiseOrNot = 0;
		for (DWORD i = 0; i < dwPrimCount; i++) {
			currentFace->v_1 = (DWORD)(*pSrc);

			// Normal Order
			if (!(clockwiseOrNot & 0x0)) {
				currentFace->v_2 = (DWORD)(*(pSrc + 1));
				currentFace->v_3 = (DWORD)(*(pSrc + 2));
			}

			// Anticlockwise Order
			else {
				currentFace->v_2 = (DWORD)(*(pSrc + 2));
				currentFace->v_3 = (DWORD)(*(pSrc + 1));
			}

			clockwiseOrNot++;
			currentFace++;
			pSrc++;
		}
	}
}

HRESULT obtainIndexBuffer(ID3D11DeviceContext* pContext, FACES* pFaces, UINT StartIndexLocation, INT BaseVertexLocation, D3D_PRIMITIVE_TOPOLOGY primitiveType) {
	// Dumps into a new buffer from GPU Memory
	ID3D11Buffer* copiedIndexBuffer = NULL;

	// Store Obtained information
	ID3D11Buffer* obtainedIndexBuffer = NULL;
	DXGI_FORMAT obtainedFormat = DXGI_FORMAT_UNKNOWN;
	UINT offset = 0;

	// Get Index Buffer
	pContext->IAGetIndexBuffer(&obtainedIndexBuffer, &obtainedFormat, &offset);
	if (!obtainedIndexBuffer) {
		OutputDebugStringW(L"ERROR 3: Index Buffer Get Failed");
		return E_FAIL;
	}

	// Copy obtained index buffer to readable buffer
	if (copyBuffer(pContext, obtainedIndexBuffer, &copiedIndexBuffer) != S_OK) {
		OutputDebugStringW(L"ERROR 3: Copy Failed");
		SAFE_RELEASE(obtainedIndexBuffer);
		return E_FAIL;
	}

	// Map resource to make it readable
	D3D11_MAPPED_SUBRESOURCE mapData;
	ZeroMemory(&mapData, sizeof(mapData));
	if (pContext->Map(copiedIndexBuffer, 0, D3D11_MAP_READ, 0, &mapData) != S_OK) {
		OutputDebugStringW(L"ERROR 3: Mapping Subresource Failed");
		SAFE_RELEASE(obtainedIndexBuffer);
		SAFE_RELEASE(copiedIndexBuffer);
		return E_FAIL;
	}

	// Check format of index buffer and Dump Index buffer
	// Indices can be either 16 or 32 bit
	BYTE* pIndexData = (BYTE*)mapData.pData + offset;

	if (obtainedFormat == DXGI_FORMAT_R16_UINT) {
		dumpIndexesToFaces<WORD>((WORD*)pIndexData, 16, StartIndexLocation, pFaces, primitiveType);
	}
	else if (obtainedFormat == DXGI_FORMAT_R32_UINT) {
		dumpIndexesToFaces<DWORD>((DWORD*)pIndexData, 32, StartIndexLocation, pFaces, primitiveType);
	}
	else {
		OutputDebugStringW(L"ERROR 3: Obtained Format of Index buffer unknown");
		pContext->Unmap(copiedIndexBuffer, 0);
		SAFE_RELEASE(obtainedIndexBuffer);
		SAFE_RELEASE(copiedIndexBuffer);
		return E_FAIL;
	}

	// Need to add minimum index to the index buffer since we could be starting at any point inside index buffer
	// as specified by DrawIndexed or other draw calls. We have already added offset and StartIndexLocation,
	// now we need to add either BaseVertexLocation or BaseIndexLocation = pFaces->minIndex
	DWORD minIdx = pFaces->minIndex;
	for (DWORD i = 0; i < pFaces->primitiveCount; i++) {
		pFaces->pFaces->v_1 += -(INT)minIdx;
		pFaces->pFaces->v_2 += -(INT)minIdx;
		pFaces->pFaces->v_3 += -(INT)minIdx;
	}


	// Clean up resources
	pContext->Unmap(copiedIndexBuffer, 0);
	SAFE_RELEASE(obtainedIndexBuffer);
	SAFE_RELEASE(copiedIndexBuffer);

	// Return
	return S_OK;
}

//-------------------------------------------- STEP 4 --------------------------------------------
void DumpInputElementToBuffer(DXGI_FORMAT elemType, BYTE* pSrc, DWORD srcOffset, DWORD srcVertexSize, BYTE* pDest, DWORD destOffset, DWORD destVertexSize, DWORD vertexCount) {
	// Iterate through all the vertices and copy the data of just this one semantic element (e.g. POSTION to VERTICES array)
	for (DWORD i = 0; i < vertexCount; i++) {
		BYTE unpackedData[64];
		DWORD compCnt = 0;
		DWORD dataSize = 0;

		// Copy element data to unpacked array
		dataSize = D3DTypesDatabase::decodeAndCopy(elemType, pSrc+srcOffset, unpackedData, compCnt);

		// Copy data from vertex buffer to list of VERTICES
		memcpy(pDest + destOffset, unpackedData, dataSize);

		// Add to index we are at
		pSrc += srcVertexSize;
		pDest += destVertexSize;
	}
}

HRESULT obtainVertexBuffer(ID3D11DeviceContext* pContext, FACES* pFaces, VERTICES* pVertices, InputVertexDeclaration &inputVertexDeclaration, OutputVertexDeclaration &outputVertexDeclaration, INT BaseVertexLocation) {
	// Dumps into a new buffer from GPU Memory
	// Obtain vertex buffers from every slot in this draw call
	for (size_t i = 0; i < inputVertexDeclaration.declaration.size(); i++) {
		// Starting Locals
		InputD3D11VertexElement inputElement = inputVertexDeclaration.declaration[i];
		OutputD3D11VertexElement outputElement = outputVertexDeclaration.declaration[i];
		ID3D11Buffer* pVertexBuffer;
		ID3D11Buffer* pDestVertexBuffer;
		UINT vertexStride = 0;
		UINT vertexOffset = 0;

		// Obtain the vertex buffers for this draw call
		pContext->IAGetVertexBuffers(inputElement.InputSlot, 1, &pVertexBuffer, &vertexStride, &vertexOffset);
		if (!pVertexBuffer) {
			OutputDebugStringW(L"4 ERROR: No Vertex Buffer obtained");
			return E_FAIL;
		}

		// Copy buffer to Destination buffer
		copyBuffer(pContext, pVertexBuffer, &pDestVertexBuffer);

		// Map resource to be read from
		D3D11_MAPPED_SUBRESOURCE mapData;
		ZeroMemory(&mapData, sizeof(mapData));
		if (pContext->Map(pDestVertexBuffer, 0, D3D11_MAP_READ, 0, &mapData) != S_OK) {
			OutputDebugStringW(L"4 ERROR: No Mapping obtained");
			SAFE_RELEASE(pVertexBuffer);
			SAFE_RELEASE(pDestVertexBuffer);
			return E_FAIL;
		}
		
		// Obtain Vertices and Faces from Vertex Semantic
		// This obtains each Input element into the VERTICES array. Each element is added one at a time
		// This way, we can extract all feature of every vertex and place them into an array of vertices.
		// Which we can then use to extract to an obj file
		BYTE* pVertexData = (BYTE*)mapData.pData + vertexOffset;

		// Dump this particular input element from the vertex buffer into the VERTICES array
		DumpInputElementToBuffer(inputElement.Type, pVertexData + (pFaces->minIndex + BaseVertexLocation) * vertexStride, inputElement.Offset, vertexStride, pVertices->pVertices, outputElement.Offset, pVertices->VertexSize, pVertices->VertexCount);
		
		// Unmap and Free all resources to avoid memory leaks
		pContext->Unmap(pDestVertexBuffer, 0);
		SAFE_RELEASE(pDestVertexBuffer);
		SAFE_RELEASE(pVertexBuffer);
	}

	return S_OK;
}

//-------------------------------------------- STEP 5 --------------------------------------------
void extractMeshToFile(VERTICES vertices, FACES faces) {
	// Extract Vertices and Faces to .obj file
}

//------------------------------------------------------------------------------------------------
//  
//									HOOKED FUNCTIONS - IMPORTANT
// 
//------------------------------------------------------------------------------------------------
// Each draw call has its own Input-Assembly and thus maybe has multiple vertex buffers and
// input slots. Potentially, the hook can be enabled in the middle of any particular draw call.
// As a result, we must keep track of all the input assemblies we have so far extracted inside
// a database so we don't end up in an infinite loop.

void VertexInputAssemblies::addInputAssembly(ID3D11InputLayout* ppInputLayout, OrigD3D11VertexDeclaration inputElements) {
	vertexInputStore.insert({ ppInputLayout, inputElements });
}

UINT VertexInputAssemblies::getInputAssembly(ID3D11InputLayout* currentInputLayout, OrigD3D11VertexDeclaration& declaration) {
	auto iterator = sceneData.vertexInputStore.find(currentInputLayout);

	if (iterator != sceneData.vertexInputStore.end()) {
		OutputDebugStringA("OVD ERROR: No Input Layout found!");
		return E_FAIL;
	}

	// Obtain Vertex Declaration from this
	declaration = iterator->second;

	// Return OK
	return S_OK;
}

HRESULT __stdcall hkCreateInputLayout(ID3D11Device* pDevice, const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs, UINT NumElements, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength, ID3D11InputLayout** ppInputLayout) {
	// Create the input layout
	if (pCreateInputLayoutDummy(pDevice, pInputElementDescs, NumElements, pShaderBytecodeWithInputSignature, BytecodeLength, ppInputLayout) != S_OK) {
		//OutputDebugStringW(L"ERROR 0: Could not create input layout!");
		return E_FAIL;

	}

	//DUMP1 = true;
	//DUMP2 = true; not supp to be here
	/*if (DUMP1 && DUMP2 || !DUMP1 && !DUMP2) {
		return S_OK;
	}*/

	//OutputDebugStringW(L"Successfully passed stage 0!");

	// Find if it already exists and update it
	auto mapIterator = sceneData.vertexInputStore.find(*ppInputLayout);
	if (mapIterator != sceneData.vertexInputStore.end()) {
		sceneData.vertexInputStore.erase(mapIterator);
	}

	//OutputDebugStringW(L"Successfully passed stage 1!");
	
	// Add all elements to input layout
	OrigD3D11VertexDeclaration layouts;
	for (UINT i = 0; i < NumElements; i++) {
		D3D11_INPUT_ELEMENT_DESC elementDesc = pInputElementDescs[i];

		OrigD3D11InputElementDesc desc = {
			.SemanticIndex = elementDesc.SemanticIndex,
			.Format = elementDesc.Format,
			.InputSlot = elementDesc.InputSlot,
			.AlignedByteOffset = elementDesc.AlignedByteOffset,
			.InputSlotClass =  elementDesc.InputSlotClass,
			.InstanceDataStepRate = elementDesc.InstanceDataStepRate,
		};

		strcpy(desc.SemanticName, elementDesc.SemanticName);

		layouts.push_back(desc);
	}

	//OutputDebugStringW(L"Successfully passed stage 2!");

	// Add to sceneData database
	sceneData.addInputAssembly(*ppInputLayout, layouts);

	//OutputDebugStringW(L"Successfully passed stage 3!");

	// Output all the scene data currently -  Visible in debug view
	// [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
	/*for (size_t i = 0; i < layouts.size(); i++) {
		DebugLogger::print_input_element_description(layouts[i]);
	}*/
	// ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

	//OutputDebugStringW(L"Successfully passed stage 4!");
	

	// End the dumping

	return S_OK;
}

void __stdcall hkDrawIndexed(ID3D11DeviceContext* pContext, UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation) {
	// We're only dumping 1 Vertex buffer
	if (DUMP1 && DUMP2 || !DUMP1 && !DUMP2) {
		return pDrawIndexedDummy(pContext, IndexCount, StartIndexLocation, BaseVertexLocation);
	}
	
	OutputDebugStringW(L"START: Obtaining Vertex Buffer");
	DUMP2 = true;
	return pDrawIndexedDummy(pContext, IndexCount, StartIndexLocation, BaseVertexLocation);
	//################################################################################################
	// TESTING
	// Step 1: Get Vertex Declarations - Check if we've looped the scene (Check input assembly is already in data map)
	InputVertexDeclaration inputVertexDeclaration;
	OutputVertexDeclaration outputVertexDeclaration;
	obtainVertexDeclarations(pContext, inputVertexDeclaration, outputVertexDeclaration);

	// PRINT THEM
	//################################################################################################

	// Step 2: Get Primitives & Calculate number of primitives and create an array from this
	D3D11_PRIMITIVE_TOPOLOGY topology = obtainPrimitives(pContext);
	if (topology != D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP || topology != D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST) {
		OutputDebugStringW(L"ERROR S: Primitive error - Wrong primitives used");
		return pDrawIndexedDummy(pContext, IndexCount, StartIndexLocation, BaseVertexLocation);
	}
	UINT faceCount = calculatePrimitiveCount(IndexCount, topology);
	FACES faces(faceCount);

	// Step 3: Dump Index buffer
	if (obtainIndexBuffer(pContext, &faces, StartIndexLocation, BaseVertexLocation, topology) != S_OK) {
		OutputDebugStringW(L"ERROR S: Failed to Dump index buffer to Faces");
		return;
	}
	
	// Step 4: 
	//obtainVertexBuffer();

	// Step 6: Extract to .obj File
	//extractMeshToFile();

	DUMP2 = true;

	OutputDebugStringW(L"END: Finished Dump! Vertices+Faces Extracted!");
	return pDrawIndexedDummy(pContext, IndexCount, StartIndexLocation, BaseVertexLocation);
}

//------------------------------------------------------------------------------------------------
//  
//							BASE DX11 HOOK - MODIFIED FOR HOOKING - STEP 0
// 
//------------------------------------------------------------------------------------------------

void loadOriginalD3D11()
{
	originalD3D11 = LoadLibrary(".\\d3d11.o.dll");

	if (!originalD3D11)
	{
		char dllpath[MAX_PATH];
		GetSystemDirectory(dllpath, MAX_PATH);
		strcat(dllpath, "\\d3d11.dll");
		LOG(dllpath);
		originalD3D11 = LoadLibrary(dllpath);
	}

	if (!originalD3D11)
	{
		LOG("LOAD ERROR: loadOriginalD3D11: no originalD3D11 OH DEAR");
		return;
	}

#pragma region handles

	coreCreateDevice = (D3D11_Core_Create_Device)GetProcAddress(originalD3D11, "D3D11CoreCreateDevice");
	createDevice = (D3D11_Create_Device)GetProcAddress(originalD3D11, "D3D11CreateDevice");
	createDeviceAndSwapChain = (D3D11_Create_Device_And_Swap_Chain)GetProcAddress(originalD3D11, "D3D11CreateDeviceAndSwapChain");
	d3d11on12CreateDevice = (D3D11_On_12_Create_Device)GetProcAddress(originalD3D11, "D3D11On12CreateDevice");

	D3D11CreateDeviceForD3D12Org = GetProcAddress(originalD3D11, "D3D11CreateDeviceForD3D12");
	D3DKMTCloseAdapterOrg = GetProcAddress(originalD3D11, "D3DKMTCloseAdapter");
	D3DKMTDestroyAllocationOrg = GetProcAddress(originalD3D11, "D3DKMTDestroyAllocation");
	D3DKMTDestroyContextOrg = GetProcAddress(originalD3D11, "D3DKMTDestroyContext");
	D3DKMTDestroyDeviceOrg = GetProcAddress(originalD3D11, "D3DKMTDestroyDevice");
	D3DKMTDestroySynchronizationObjectOrg = GetProcAddress(originalD3D11, "D3DKMTDestroySynchronizationObject");
	D3DKMTPresentOrg = GetProcAddress(originalD3D11, "D3DKMTPresent");
	D3DKMTQueryAdapterInfoOrg = GetProcAddress(originalD3D11, "D3DKMTQueryAdapterInfo");
	D3DKMTSetDisplayPrivateDriverFormatOrg = GetProcAddress(originalD3D11, "D3DKMTSetDisplayPrivateDriverFormat");
	D3DKMTSignalSynchronizationObjectOrg = GetProcAddress(originalD3D11, "D3DKMTSignalSynchronizationObject");
	D3DKMTUnlockOrg = GetProcAddress(originalD3D11, "D3DKMTUnlock");
	D3DKMTWaitForSynchronizationObjectOrg = GetProcAddress(originalD3D11, "D3DKMTWaitForSynchronizationObject");
	EnableFeatureLevelUpgradeOrg = GetProcAddress(originalD3D11, "EnableFeatureLevelUpgrade");
	OpenAdapter10Org = GetProcAddress(originalD3D11, "OpenAdapter10");
	OpenAdapter10_2Org = GetProcAddress(originalD3D11, "OpenAdapter10_2");
	CreateDirect3D11DeviceFromDXGIDeviceOrg = GetProcAddress(originalD3D11, "CreateDirect3D11DeviceFromDXGIDevice");
	CreateDirect3D11SurfaceFromDXGISurfaceOrg = GetProcAddress(originalD3D11, "CreateDirect3D11SurfaceFromDXGISurface");
	D3D11CoreCreateLayeredDeviceOrg = GetProcAddress(originalD3D11, "D3D11CoreCreateLayeredDevice");
	D3D11CoreGetLayeredDeviceSizeOrg = GetProcAddress(originalD3D11, "D3D11CoreGetLayeredDeviceSize");
	D3D11CoreRegisterLayersOrg = GetProcAddress(originalD3D11, "D3D11CoreRegisterLayers");
	D3DKMTCreateAllocationOrg = GetProcAddress(originalD3D11, "D3DKMTCreateAllocation");
	D3DKMTCreateContextOrg = GetProcAddress(originalD3D11, "D3DKMTCreateContext");
	D3DKMTCreateDeviceOrg = GetProcAddress(originalD3D11, "D3DKMTCreateDevice");
	D3DKMTCreateSynchronizationObjectOrg = GetProcAddress(originalD3D11, "D3DKMTCreateSynchronizationObject");
	D3DKMTEscapeOrg = GetProcAddress(originalD3D11, "D3DKMTEscape");
	D3DKMTGetContextSchedulingPriorityOrg = GetProcAddress(originalD3D11, "D3DKMTGetContextSchedulingPriority");
	D3DKMTGetDeviceStateOrg = GetProcAddress(originalD3D11, "D3DKMTGetDeviceState");
	D3DKMTGetDisplayModeListOrg = GetProcAddress(originalD3D11, "D3DKMTGetDisplayModeList");
	D3DKMTGetMultisampleMethodListOrg = GetProcAddress(originalD3D11, "D3DKMTGetMultisampleMethodList");
	D3DKMTGetRuntimeDataOrg = GetProcAddress(originalD3D11, "D3DKMTGetRuntimeData");
	D3DKMTGetSharedPrimaryHandleOrg = GetProcAddress(originalD3D11, "D3DKMTGetSharedPrimaryHandle");
	D3DKMTLockOrg = GetProcAddress(originalD3D11, "D3DKMTLock");
	D3DKMTOpenAdapterFromHdcOrg = GetProcAddress(originalD3D11, "D3DKMTOpenAdapterFromHdc");
	D3DKMTOpenResourceOrg = GetProcAddress(originalD3D11, "D3DKMTOpenResource");
	D3DKMTQueryAllocationResidencyOrg = GetProcAddress(originalD3D11, "D3DKMTQueryAllocationResidency");
	D3DKMTQueryResourceInfoOrg = GetProcAddress(originalD3D11, "D3DKMTQueryResourceInfo");
	D3DKMTRenderOrg = GetProcAddress(originalD3D11, "D3DKMTRender");
	D3DKMTSetAllocationPriorityOrg = GetProcAddress(originalD3D11, "D3DKMTSetAllocationPriority");
	D3DKMTSetContextSchedulingPriorityOrg = GetProcAddress(originalD3D11, "D3DKMTSetContextSchedulingPriority");
	D3DKMTSetDisplayModeOrg = GetProcAddress(originalD3D11, "D3DKMTSetDisplayMode");
	D3DKMTSetGammaRampOrg = GetProcAddress(originalD3D11, "D3DKMTSetGammaRamp");
	D3DKMTSetVidPnSourceOwnerOrg = GetProcAddress(originalD3D11, "D3DKMTSetVidPnSourceOwner");
	D3DKMTWaitForVerticalBlankEventOrg = GetProcAddress(originalD3D11, "D3DKMTWaitForVerticalBlankEvent");
	D3DPerformance_BeginEventOrg = GetProcAddress(originalD3D11, "D3DPerformance_BeginEvent");
	D3DPerformance_EndEventOrg = GetProcAddress(originalD3D11, "D3DPerformance_EndEvent");
	D3DPerformance_GetStatusOrg = GetProcAddress(originalD3D11, "D3DPerformance_GetStatus");
	D3DPerformance_SetMarkerOrg = GetProcAddress(originalD3D11, "D3DPerformance_SetMarker");

#pragma endregion

}

HRESULT WINAPI D3D11CoreCreateDevice(IDXGIFactory* pFactory, IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, UINT SDKVersion, ID3D11Device** ppDevice, D3D_FEATURE_LEVEL* pFeatureLevel)
{
	LOG("INIT: D3D11CoreCreateDevice");

	if (!originalD3D11)
	{
		LOG("INIT ERROR: D3D11CoreCreateDevice: no originalD3D11");
		return DXGI_ERROR_NOT_FOUND;
	}

	HRESULT result;
	result = coreCreateDevice(pFactory, pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel);

	if (result != S_OK)
		LOG("INIT: D3D11CoreCreateDevice: " + int_to_hex(result));
	else
		LOG("INIT: D3D11CoreCreateDevice: OK!");

	return result;
}

HRESULT WINAPI D3D11CreateDevice(IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, UINT SDKVersion, ID3D11Device** ppDevice, D3D_FEATURE_LEVEL* pFeatureLevel, ID3D11DeviceContext** ppImmediateContext)
{
	LOG("INIT: D3D11CreateDevice, FeatureLevels: " + std::to_string(FeatureLevels));

	if (FeatureLevels > 0)
	{
		for (size_t i = 0; i < FeatureLevels; i++)
		{
			LOG("INIT: D3D11CreateDevice, pFeatureLevels[" + std::to_string(i) + "]: " + int_to_hex(pFeatureLevels[i]));
		}
	}

	if (!originalD3D11)
	{
		LOG("INIT ERROR: D3D11CreateDevice: no originalD3D11");
		return DXGI_ERROR_NOT_FOUND;
	}

	HRESULT result;

#ifndef CREATE_DX12
	result = createDevice(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext);

	if (result != S_OK) {
		LOG("INIT: D3D11CreateDevice: " + int_to_hex(result));
	}
	else {
		LOG("INIT: D3D11CreateDevice: OK!");
		
		// Step 1: Hook into drawIndexed
		MH_STATUS status = MH_Initialize();
		if (status != MH_OK) {
			OutputDebugStringW(L"HOOK ERROR: FAILED TO INIT");
			return result;
		}

		OutputDebugStringW(L"HOOK: ATTEMPTING HOOK");

		void** drawContextVTable = *reinterpret_cast<void***>(*ppImmediateContext);
		pDrawIndexedOriginal = (DrawIndexed_t)drawContextVTable[12];

		void** deviceContextVTable = *reinterpret_cast<void***>(*ppDevice);
		pCreateInputLayoutOriginal = (CreateInputLayout_t)deviceContextVTable[11];

		// First hook into CreateInputLayout
		if (MH_CreateHook(reinterpret_cast<void**>(pCreateInputLayoutOriginal), &hkCreateInputLayout, reinterpret_cast<void**>(&pCreateInputLayoutDummy)) != MH_OK) {
			OutputDebugStringW(L"HOOK ERROR 1: WE HAVE NOT HOOKED");
			return result;
		}
		
		if (MH_EnableHook(pCreateInputLayoutOriginal) != MH_OK) {
			OutputDebugStringW(L"HOOK ERROR 1: NOT ENABLED");
			return result;
		}
		
		OutputDebugStringW(L"HOOK: CreateInputLayout Succeeded!");

		// Second hook into DrawIndexed
		if (MH_CreateHook(reinterpret_cast<void**>(pDrawIndexedOriginal), &hkDrawIndexed, reinterpret_cast<void**>(&pDrawIndexedDummy)) != MH_OK) {
			OutputDebugStringW(L"HOOK ERROR 2: WE HAVE NOT HOOKED");
			return result;
		}

		if (MH_EnableHook(pDrawIndexedOriginal) != MH_OK) {
			OutputDebugStringW(L"HOOK ERROR 2: WE HAVE NOT HOOKED");
			return result;
		}

		OutputDebugStringW(L"HOOK: DrawIndexed Succeeded!");

	}

#else
	ID3D12Device* d3d12device = nullptr;

	if (FeatureLevels > 0)
	{
		bool ok = false;

		for (size_t i = 0; i < FeatureLevels; i++)
		{
			result = D3D12CreateDevice(pAdapter, pFeatureLevels[i], IID_PPV_ARGS(&d3d12device));
			LOG("D3D11CreateDevice D3D12CreateDevice " + int_to_hex(pFeatureLevels[i]) + " result: " + int_to_hex(result));

			if (result == S_OK)
			{
				ok = true;
				break;
			}
		}

		if (!ok)
		{
			LOG("D3D11CreateDevice: " + int_to_hex(result));
			return result;
		}
	}
	else
	{
		result = D3D12CreateDevice(pAdapter, D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&d3d12device));
		LOG("D3D11CreateDevice D3D12CreateDevice D3D_FEATURE_LEVEL_12_0 result: " + int_to_hex(result));

		if (result != S_OK)
		{

			result = D3D12CreateDevice(pAdapter, D3D_FEATURE_LEVEL_11_1, IID_PPV_ARGS(&d3d12device));
			LOG("D3D11CreateDevice D3D12CreateDevice D3D_FEATURE_LEVEL_11_1 result: " + int_to_hex(result));

			if (result != S_OK)
			{
				result = D3D12CreateDevice(pAdapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&d3d12device));
				LOG("D3D11CreateDevice D3D12CreateDevice D3D_FEATURE_LEVEL_11_0 result: " + int_to_hex(result));

				if (result != S_OK)
					return result;
			}
		}
	}

	if (d3d12device == nullptr)
		return E_NOINTERFACE;

	LOG("D3D11CreateDevice d3d12device created!");

	D3D12_COMMAND_QUEUE_DESC desc;
	desc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
	desc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_HIGH;
	desc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	desc.NodeMask = 0;

	ID3D12CommandQueue* d3d12queue;
	result = d3d12device->CreateCommandQueue(&desc, IID_PPV_ARGS(&d3d12queue));

	if (result != S_OK)
	{
		LOG("D3D11CreateDevice can't CreateCommandQueue!");
		return result;
	}

	LOG("D3D11CreateDevice d3d12queue created!");
	result = D3D11On12CreateDevice(d3d12device, Flags, pFeatureLevels, FeatureLevels, (IUnknown**)&d3d12queue, 1, 0, ppDevice, ppImmediateContext, pFeatureLevel);

	//d3d12device->Release();
#endif

	return result;
}

HRESULT WINAPI D3D11CreateDeviceAndSwapChain(IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, UINT SDKVersion, const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc, IDXGISwapChain** ppSwapChain, ID3D11Device** ppDevice, D3D_FEATURE_LEVEL* pFeatureLevel, ID3D11DeviceContext** ppImmediateContext)
{
	LOG("INIT: D3D11CreateDeviceAndSwapChain");

	if (ppSwapChain && !pSwapChainDesc)
		return E_INVALIDARG;

	if (!originalD3D11)
	{
		LOG("INIT ERROR: D3D11CreateDeviceAndSwapChain: no originalD3D11");
		return DXGI_ERROR_NOT_FOUND;
	}

	HRESULT result;

#ifndef CREATE_DX12
	result = createDeviceAndSwapChain(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext);

	LOG("INIT: D3D11CreateDeviceAndSwapChain result: " + int_to_hex(result));

	/*MH_STATUS status = MH_Initialize();
	if (status != MH_OK) {
		OutputDebugStringW(L"HOOK: INITIALISING MHOOK COMPLETE");
		return result;
	}

	OutputDebugStringW(L"HOOK: ATTEMPTING HOOK");

	void** drawContextVTable = *reinterpret_cast<void***>(*ppImmediateContext);
	pDrawIndexedOriginal = (DrawIndexed_t)drawContextVTable[12];

	if (MH_CreateHook(reinterpret_cast<void**>(pDrawIndexedOriginal), &hkDrawIndexed, reinterpret_cast<void**>(pDrawIndexedDummy)) != MH_OK) {
		OutputDebugStringW(L"HOOK: WE HAVE NOT HOOKED");
		return result;
	}

	OutputDebugStringW(L"HOOK: WE HAVE HOOK!");

	if (MH_EnableHook(pDrawIndexedOriginal) != MH_OK) {
		return result;
	}*/

	return result;
#else
	if (ppSwapChain && !pSwapChainDesc)
		return E_INVALIDARG;

	ID3D11Device* d3d11Device;
	ID3D11DeviceContext* d3d11Context;

	result = D3D11CreateDevice(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, &d3d11Device, pFeatureLevel, &d3d11Context);
	LOG("D3D11CreateDeviceAndSwapChain for Dx12 result: " + int_to_hex(result));

	if (ppSwapChain)
	{
		IDXGIDevice* dxgiDevice = nullptr;
		IDXGIAdapter* dxgiAdapter = nullptr;
		IDXGIFactory* dxgiFactory = nullptr;

		result = d3d11Device->QueryInterface(IID_PPV_ARGS(&dxgiDevice));
		LOG("D3D11CreateDeviceAndSwapChain d3d11Device->QueryInterface result: " + int_to_hex(result));

		if (result != S_OK)
			return E_INVALIDARG;

		result = dxgiDevice->GetParent(IID_PPV_ARGS(&dxgiAdapter));
		dxgiDevice->Release();
		LOG("D3D11CreateDeviceAndSwapChain dxgiDevice->GetParent result: " + int_to_hex(result));

		if (result != S_OK)
			return E_INVALIDARG;

		result = dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory));
		dxgiAdapter->Release();
		LOG("D3D11CreateDeviceAndSwapChain dxgiAdapter->GetParent result: " + int_to_hex(result));

		if (result != S_OK)
			return E_INVALIDARG;

		DXGI_SWAP_CHAIN_DESC desc = *pSwapChainDesc;
		result = dxgiFactory->CreateSwapChain(d3d11Device, &desc, ppSwapChain);
		dxgiFactory->Release();
		LOG("D3D11CreateDeviceAndSwapChain dxgiFactory->CreateSwapChain result: " + int_to_hex(result));

		if (result != S_OK)
			return result;
	}

	if (ppDevice != nullptr)
		*ppDevice = d3d11Device;
	else
		d3d11Device->Release();

	if (ppImmediateContext != nullptr)
		*ppImmediateContext = d3d11Context;
	else
		d3d11Context->Release();

	return S_OK;
#endif

}

HRESULT WINAPI D3D11On12CreateDevice(IUnknown* pDevice, UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, IUnknown* const* ppCommandQueues, UINT NumQueues, UINT NodeMask, ID3D11Device** ppDevice, ID3D11DeviceContext** ppImmediateContext, D3D_FEATURE_LEVEL* pChosenFeatureLevel)
{
	LOG("D3D11 CREATE DEVICE: D3D11On12CreateDevice");

	if (!originalD3D11)
	{
		LOG("D3D11 ERROR: D3D11On12CreateDevice: no originalD3D11");
		return DXGI_ERROR_NOT_FOUND;
	}

	auto result = d3d11on12CreateDevice(pDevice, Flags, pFeatureLevels, FeatureLevels, ppCommandQueues, NumQueues, NodeMask, ppDevice, ppImmediateContext, pChosenFeatureLevel);

	if (result == S_OK)
		LOG("D3D11 COMPLETE: D3D11On12CreateDevice: " + int_to_hex(result));
	else
		LOG("D3D11 COMPLETE: D3D11On12CreateDevice: OK!");

	return result;
}

DWORD __stdcall EjectThread(LPVOID lpParameter) {
	Sleep(100);
	FreeLibraryAndExitThread(dll_handle, 0);
	Sleep(100);
	return 0;
}

int WINAPI main() {
	while (true) {
		Sleep(50);

		if (GetAsyncKeyState('Q') & 1) {
			DUMP1 = true;
			OutputDebugStringW(L"Q was pressed!");
		}

		// Print global information
		if (GetAsyncKeyState('P') & 1) {
			OutputDebugStringA(std::to_string(DUMP1).c_str());
			OutputDebugStringA(std::to_string(DUMP2).c_str());

			// Check Scenedata is still working
			OutputDebugStringA(std::to_string(sceneData.vertexInputStore.size()).c_str());
		}


		if (GetAsyncKeyState(VK_F1)) {
			break;
		}
	}

	CreateThread(0, 0, EjectThread, 0, 0, 0);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{

	#ifdef LOGGING_ACTIVE
		std::time_t t = std::time(nullptr);
		std::string datetime(100, 0);
	#endif

	switch (fdwReason) {
		case DLL_PROCESS_ATTACH:
			#ifdef LOGGING_ACTIVE
				datetime.resize(std::strftime(&datetime[0], datetime.size(), "%d%m%Y_%H%M%OS", std::localtime(&t)));

				prepareOfs(".\\d3d11-proxy-" + datetime + ".log");

				LOG("ATTACH: d3d11-proxy DLL_PROCESS_ATTACH");
			#endif

			dll_handle = hinstDLL;
			loadOriginalD3D11();

			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)main, NULL, 0, NULL);

			break;

		case DLL_PROCESS_DETACH:
			LOG("DETACH: d3d11-proxy DLL_PROCESS_DETACH");

			if (originalD3D11)
				FreeLibrary(originalD3D11);

			#ifdef LOGGING_ACTIVE
					closeOfs();
			#endif

			if (MH_DisableHook(MH_ALL_HOOKS) != MH_OK) {
				break;
			}

			if (MH_Uninitialize() != MH_OK) {
				break;
			}

			OutputDebugStringW(L"----------------------WE HAVE ENDED!----------------------");

			break;
		}

	return TRUE;
}

//------------------------------------------------------------------------------------------------
// 
//											DEBUG LOGGER
// 
//		Required for purely debugging purposes - Print out elements and D3D11 types to screen
// 
//------------------------------------------------------------------------------------------------

void DebugLogger::print_input_element_description(OrigD3D11InputElementDesc desc) {

	OutputDebugStringA(desc.SemanticName);
	OutputDebugStringA(std::to_string(desc.SemanticIndex).c_str());
	OutputDebugStringA(std::to_string(desc.Format).c_str());
	OutputDebugStringA(std::to_string(desc.InputSlot).c_str());
	OutputDebugStringA(std::to_string(desc.AlignedByteOffset).c_str());
	if (desc.InputSlotClass == 0) {
		OutputDebugStringA("D3D11_INPUT_PER_VERTEX_DATA");
	}
	else {
		OutputDebugStringA("D3D11_INPUT_PER_INSTANCE_DATA");
	}
	OutputDebugStringA(std::to_string(desc.InstanceDataStepRate).c_str());
	OutputDebugStringA("---------------------------------------------------");
}