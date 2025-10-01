#pragma once


//------------------------------------------------------------------------------------------------
// 
//											D3D11 TYPE DATABASE
// 
//		Required for extracting types from input layouts and to extract data from vertex buffers
// 
//------------------------------------------------------------------------------------------------

enum D3DType {
	dt_UNKNOWN,

	dt_R32G32B32A32_TYPELESS,
	dt_R32G32B32A32_FLOAT,
	dt_R32G32B32A32_UINT,
	dt_R32G32B32A32_SINT,

	dt_R32G32B32_TYPELESS,
	dt_R32G32B32_FLOAT,
	dt_R32G32B32_UINT,
	dt_R32G32B32_SINT,

	dt_R32G32_TYPELESS,
	dt_R32G32_FLOAT,
	dt_R32G32_UINT,
	dt_R32G32_SINT,

	dt_R32_TYPELESS,
	dt_D32_FLOAT,
	dt_R32_FLOAT,
	dt_R32_UINT,
	dt_R32_SINT,

	dt_R16G16B16A16_TYPELESS,
	dt_R16G16B16A16_FLOAT,
	dt_R16G16B16A16_UNORM,
	dt_R16G16B16A16_UINT,
	dt_R16G16B16A16_SNORM,
	dt_R16G16B16A16_SINT,

	dt_R16G16_TYPELESS,
	dt_R16G16_FLOAT,
	dt_R16G16_UNORM,
	dt_R16G16_UINT,
	dt_R16G16_SNORM,
	dt_R16G16_SINT,

	dt_R16_TYPELESS,
	dt_R16_FLOAT,
	dt_D16_UNORM,
	dt_R16_UNORM,
	dt_R16_UINT,
	dt_R16_SNORM,
	dt_R16_SINT,

	dt_R8G8B8A8_TYPELESS,
	dt_R8G8B8A8_UNORM ,
	dt_R8G8B8A8_UNORM_SRGB,
	dt_R8G8B8A8_UINT,
	dt_R8G8B8A8_SNORM,
	dt_R8G8B8A8_SINT,

	dt_R8G8_TYPELESS,
	dt_R8G8_UNORM,
	dt_R8G8_UINT,
	dt_R8G8_SNORM,
	dt_R8G8_SINT,

	dt_R8_TYPELESS,
	dt_R8_UNORM,
	dt_R8_UINT,
	dt_R8_SNORM,
	dt_R8_SINT,
	dt_A8_UNORM,
};

class D3DTypesDatabase {
public:
	//---------------- Type property obtainers ----------------
	static D3DType dp_convert_dxgi_type(); // May not need this, can just use DXGI format upfront?

	static DWORD dp_obtainTypeSize(DXGI_FORMAT format);
	static DWORD dp_obtainTypeSize(D3DType type);

	//----------------- Type memory decoders ------------------
	static DWORD decodeAndCopy(DXGI_FORMAT format, const void* pSrc, void* pDst, DWORD& compCnt);
	static DWORD decodeAndCopy(D3DType type, const void* pSrc, void* pDst, DWORD& compCnt);

	//----------------- Type memory obtainers -----------------
	static DWORD dt_unknownType();

	// 32 bytes - Traditionally used first implemented
	static DWORD dt_R32G32B32A32_TYPELESS(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32G32B32A32_FLOAT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32G32B32A32_UINT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32G32B32A32_SINT(const void* pData, void* pUnpacked, DWORD& compCnt);

	static DWORD dt_R32G32B32_TYPELESS(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32G32B32_FLOAT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32G32B32_UINT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32G32B32_SINT(const void* pData, void* pUnpacked, DWORD& compCnt);

	static DWORD dt_R32G32_TYPELESS(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32G32_FLOAT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32G32_UINT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32G32_SINT(const void* pData, void* pUnpacked, DWORD& compCnt);

	static DWORD dt_R32_TYPELESS(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_D32_FLOAT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32_FLOAT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32_UINT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R32_SINT(const void* pData, void* pUnpacked, DWORD& compCnt);

	// 16 bytes - includes UNORM and SNORM type obtainers
	static DWORD dt_R16G16B16A16_TYPELESS(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16G16B16A16_FLOAT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16G16B16A16_UNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16G16B16A16_UINT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16G16B16A16_SNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16G16B16A16_SINT(const void* pData, void* pUnpacked, DWORD& compCnt);

	static DWORD dt_R16G16_TYPELESS(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16G16_FLOAT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16G16_UNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16G16_UINT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16G16_SNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16G16_SINT(const void* pData, void* pUnpacked, DWORD& compCnt);

	static DWORD dt_R16_TYPELESS(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16_FLOAT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16_UNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	//static DWORD dt_D16_UNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16_UINT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16_SNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R16_SINT(const void* pData, void* pUnpacked, DWORD& compCnt);

	// 8 bytes - includes UNORM and SNORM type obtainers
	static DWORD dt_R8G8B8A8_TYPELESS(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8G8B8A8_UNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	//static DWORD dt_R8G8B8A8_UNORM_SRGB(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8G8B8A8_UINT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8G8B8A8_SNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8G8B8A8_SINT(const void* pData, void* pUnpacked, DWORD& compCnt);

	static DWORD dt_R8G8_TYPELESS(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8G8_UNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8G8_UINT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8G8_SNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8G8_SINT(const void* pData, void* pUnpacked, DWORD& compCnt);

	static DWORD dt_R8_TYPELESS(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8_UNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8_UINT(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8_SNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
	static DWORD dt_R8_SINT(const void* pData, void* pUnpacked, DWORD& compCnt);

	//static DWORD dt_A8_UNORM(const void* pData, void* pUnpacked, DWORD& compCnt);
};