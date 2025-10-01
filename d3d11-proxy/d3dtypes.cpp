#pragma once

#include "pch.h"
#include "d3d11.h"
#include "d3dtypes.h"

//------------------------------------------------------------------------------------------------
// 
//										DirectX 11 Type Database
// 
//    Purpose of this class is to essentially take in DirectX 11 data types and convert them
//    such that they are capable of being copied into our own arrays and data structures
// 
//	  It is important to do this because DirectX 11 has its own set of data types and thus,
//	  converting them into usable types for our arrays allows us to extract data more easily
// 
//	  We also need to understand the size of the data types that DirectX 11 uses so that we 
//	  don't overwrite on vertex data and index data.  
//		
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
//  
//										TYPE PROPERTY OBTAINERS
// 
//------------------------------------------------------------------------------------------------

DWORD D3DTypesDatabase::dp_obtainTypeSize(DXGI_FORMAT format) {

	switch (format) {

		case DXGI_FORMAT_UNKNOWN:
			return 0;

		case DXGI_FORMAT_R32G32B32A32_TYPELESS:
		case DXGI_FORMAT_R32G32B32A32_FLOAT:
		case DXGI_FORMAT_R32G32B32A32_SINT:
		case DXGI_FORMAT_R32G32B32A32_UINT:
			return 16;

		case DXGI_FORMAT_R32G32B32_TYPELESS:
		case DXGI_FORMAT_R32G32B32_FLOAT:
		case DXGI_FORMAT_R32G32B32_SINT:
		case DXGI_FORMAT_R32G32B32_UINT:
			return 12;

		case DXGI_FORMAT_R16G16B16A16_TYPELESS:
		case DXGI_FORMAT_R16G16B16A16_FLOAT:
		case DXGI_FORMAT_R16G16B16A16_SINT:
		case DXGI_FORMAT_R16G16B16A16_UINT:
		case DXGI_FORMAT_R16G16B16A16_SNORM:
		case DXGI_FORMAT_R16G16B16A16_UNORM:
		case DXGI_FORMAT_R32G32_TYPELESS:
		case DXGI_FORMAT_R32G32_FLOAT:
		case DXGI_FORMAT_R32G32_SINT:
		case DXGI_FORMAT_R32G32_UINT:
			return 8;

		case DXGI_FORMAT_R8G8B8A8_TYPELESS:
		case DXGI_FORMAT_R8G8B8A8_SINT:
		case DXGI_FORMAT_R8G8B8A8_UINT:
		case DXGI_FORMAT_R8G8B8A8_SNORM:
		case DXGI_FORMAT_R8G8B8A8_UNORM:
		case DXGI_FORMAT_R16G16_TYPELESS:
		case DXGI_FORMAT_R16G16_FLOAT:
		case DXGI_FORMAT_R16G16_SINT:
		case DXGI_FORMAT_R16G16_UINT:
		case DXGI_FORMAT_R16G16_SNORM:
		case DXGI_FORMAT_R16G16_UNORM:
		case DXGI_FORMAT_R32_TYPELESS:
		case DXGI_FORMAT_R32_FLOAT:
		case DXGI_FORMAT_R32_SINT:
		case DXGI_FORMAT_R32_UINT:
		case DXGI_FORMAT_R10G10B10A2_UNORM:
		case DXGI_FORMAT_B8G8R8A8_UNORM:
			return 4;

		case DXGI_FORMAT_R8G8_TYPELESS:
		case DXGI_FORMAT_R8G8_UNORM:
		case DXGI_FORMAT_R8G8_UINT:
		case DXGI_FORMAT_R8G8_SNORM:
		case DXGI_FORMAT_R8G8_SINT:
		case DXGI_FORMAT_R16_TYPELESS:
		case DXGI_FORMAT_R16_FLOAT:
		case DXGI_FORMAT_R16_UNORM:
		case DXGI_FORMAT_R16_UINT:
		case DXGI_FORMAT_R16_SNORM:
		case DXGI_FORMAT_R16_SINT:
			return 2;

		case DXGI_FORMAT_R8_TYPELESS:
		case DXGI_FORMAT_R8_UINT:
		case DXGI_FORMAT_R8_SINT:
		case DXGI_FORMAT_R8_SNORM:
		case DXGI_FORMAT_R8_UNORM:
			return 1;
	}

	return 0;
}


//------------------------------------------------------------------------------------------------
//  
//										 TYPE MEMORY DECODERS
// 
//------------------------------------------------------------------------------------------------

///////////////////////////
// FINISH THIS OFF PLESSSSSSSSSSSSSSSSS - OUTPUT VERTEX OFFSETS ARE INCORRECT BROTHER
////////////////////////////
DWORD D3DTypesDatabase::decodeAndCopy(DXGI_FORMAT format, const void* pSrc, void* pDst, DWORD& numberOfData) {
	// For each DXGI format, decode and obtain correct memory from vertex buffer
	switch (format) {

	case (DXGI_FORMAT_R32G32B32A32_TYPELESS):
		return dt_R32G32B32A32_TYPELESS(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32G32B32A32_FLOAT):
		return dt_R32G32B32A32_FLOAT(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32G32B32A32_UINT):
		return dt_R32G32B32A32_UINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R32G32B32A32_SINT):
		return dt_R32G32B32A32_SINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R32G32B32_TYPELESS):
		return dt_R32G32B32_TYPELESS(pSrc, pDst, numberOfData);
		
	case (DXGI_FORMAT_R32G32B32_FLOAT):
		return dt_R32G32B32_FLOAT(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32G32B32_UINT):
		return dt_R32G32B32_UINT(pSrc, pDst, numberOfData);
		
	case (DXGI_FORMAT_R32G32B32_SINT):
		return dt_R32G32B32_SINT(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32G32_TYPELESS):
		return dt_R32G32_TYPELESS(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32G32_FLOAT):
		return dt_R32G32_FLOAT(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32G32_UINT):
		return dt_R32G32_UINT(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32G32_SINT):
		return dt_R32G32_SINT(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32_TYPELESS):
		return dt_R32_TYPELESS(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_D32_FLOAT):
		return dt_D32_FLOAT(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32_FLOAT):
		return dt_R32_FLOAT(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32_UINT):
		return dt_R32_UINT(pSrc, pDst, numberOfData);

	case (DXGI_FORMAT_R32_SINT):
		return dt_R32_SINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16G16B16A16_TYPELESS):
		return dt_R16G16B16A16_TYPELESS(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16G16B16A16_FLOAT):
		return dt_R16G16B16A16_FLOAT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16G16B16A16_UNORM):
		return dt_R16G16B16A16_UNORM(pSrc, pDst, numberOfData);
	
	case(DXGI_FORMAT_R16G16B16A16_UINT):
		return dt_R16G16B16A16_UINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16G16B16A16_SNORM):
		return dt_R16G16B16A16_SNORM(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16G16B16A16_SINT):
		return dt_R16G16B16A16_SINT(pSrc, pDst, numberOfData);
		
	case(DXGI_FORMAT_R16G16_TYPELESS):
		return dt_R16G16_TYPELESS(pSrc, pDst, numberOfData);
	
	case(DXGI_FORMAT_R16G16_FLOAT):
		return dt_R16G16_FLOAT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16G16_UNORM):
		return dt_R16G16_UNORM(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16G16_UINT):
		return dt_R16G16_UINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16G16_SNORM):
		return dt_R16G16_SNORM(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16G16_SINT):
		return dt_R16G16_SINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16_TYPELESS):
		return dt_R16_TYPELESS(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16_FLOAT):
		return dt_R16_FLOAT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16_UNORM):
		return dt_R16_UNORM(pSrc, pDst, numberOfData);

	/*case(DXGI_FORMAT_D16_UNORM):
		return dt_D16_UNORM(pSrc, pDst, numberOfData);*/

	case(DXGI_FORMAT_R16_UINT):
		return dt_R16_UINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16_SNORM):
		return dt_R16_SNORM(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R16_SINT):
		return dt_R16_SINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8G8B8A8_TYPELESS):
		return dt_R8G8B8A8_TYPELESS(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8G8B8A8_UNORM):
		return dt_R8G8B8A8_UNORM(pSrc, pDst, numberOfData);

	/*case(DXGI_FORMAT_R8G8B8A8_UNORM_SRGB):
		return dt_R8G8B8A8_UNORM_SRGB(pSrc, pDst, numberOfData);*/

	case(DXGI_FORMAT_R8G8B8A8_UINT):
		return dt_R8G8B8A8_UINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8G8B8A8_SNORM):
		return dt_R8G8B8A8_SNORM(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8G8B8A8_SINT):
		return dt_R8G8B8A8_SINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8G8_TYPELESS):
		return dt_R8G8_TYPELESS(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8G8_UNORM):
		return dt_R8G8_UNORM(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8G8_UINT):
		return dt_R8G8_UINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8G8_SNORM):
		return dt_R8G8_SNORM(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8G8_SINT):
		return dt_R8G8_SINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8_TYPELESS):
		return dt_R8_TYPELESS(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8_UNORM):
		return dt_R8_UNORM(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8_UINT):
		return dt_R8_UINT(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8_SNORM):
		return dt_R8_SNORM(pSrc, pDst, numberOfData);

	case(DXGI_FORMAT_R8_SINT):
		return dt_R8_SINT(pSrc, pDst, numberOfData);
	}

	return 0;
}

//------------------------------------------------------------------------------------------------
//  
//										TYPE MEMORY OBTAINERS
// 
//------------------------------------------------------------------------------------------------

DWORD D3DTypesDatabase::dt_unknownType() {
	return 0;
}

//------------------------------------------------------------------------------------------------
//  
//										  MEMORY CONVERTERS
// 
//------------------------------------------------------------------------------------------------

// From: https://github.com/mitsuba-renderer/openexr/blob/master/IlmBase/Half/toFloat.cpp
unsigned int
USHORT_to_FLOAT(unsigned short y)
{
	// Union representation to convert between
	//
	union { 
		float f; 
		DWORD i;
	} u;

	int s = (y >> 15) & 0x00000001;
	int e = (y >> 10) & 0x0000001f;
	int m = y & 0x000003ff;

	if (e == 0)
	{
		if (m == 0)
		{
			// Plus or minus zero
			return s << 31;
		}
		else
		{
			// Denormalized number -- renormalize it
			while (!(m & 0x00000400))
			{
				m <<= 1;
				e -= 1;
			}

			e += 1;
			m &= ~0x00000400;
		}
	}
	else if (e == 31)
	{
		if (m == 0)
		{
			// Positive or negative infinity
			return (s << 31) | 0x7f800000;
		}
		else
		{
			// Nan -- preserve sign and significand bits
			return (s << 31) | 0x7f800000 | (m << 13);
		}
	}

	// Normalized number
	e = e + (127 - 15);
	m = m << 13;

	// Assemble s, e and m.
	u.i = (s << 31) | (e << 23) | m;

	// Return Floating pointer number
	return u.f;
}

FLOAT SNORM_to_FLOAT(INT snormValue, INT bits) {
	FLOAT unnormalised = (FLOAT)snormValue / bits;
	return max(unnormalised, -1.0f);
}

// -------------------------------------------- 32 bit -------------------------------------------
DWORD D3DTypesDatabase::dt_R32G32B32A32_TYPELESS(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 16);
	memcpy((nDst + 0), (nSrc + 0), 4);
	memcpy((nDst + 4), (nSrc + 4), 4);
	memcpy((nDst + 8), (nSrc + 8), 4);
	memcpy((nDst + 12), (nSrc + 12), 4);

	numberOfData = 4;
	sizeOfDataType = numberOfData * 4;
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32G32B32A32_FLOAT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const FLOAT* nSrc = (FLOAT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = *(nSrc);
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);
	nDst[3] = *(nSrc + 3);

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32G32B32A32_UINT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	nDst[0] = *(nSrc);
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);
	nDst[3] = *(nSrc + 3);

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(UINT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32G32B32A32_SINT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const INT* nSrc = (INT*)pSrc;
	INT* nDst = (INT*)pDst;

	nDst[0] = *(nSrc);
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);
	nDst[3] = *(nSrc + 3);

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(INT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32G32B32_TYPELESS(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 12);
	memcpy((nDst + 0), (nSrc + 0), 4);
	memcpy((nDst + 4), (nSrc + 4), 4);
	memcpy((nDst + 8), (nSrc + 8), 4);

	numberOfData = 3;
	sizeOfDataType = numberOfData * 4;
	return sizeOfDataType;
}

// Most likely one for POSITION and NORMAL semantic to use
DWORD D3DTypesDatabase::dt_R32G32B32_FLOAT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	// Starting Locals - FLOAT because it is 4 bytes = 32 bits
	DWORD sizeOfDataType = 0;
	const FLOAT* nSrc = (FLOAT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	// 3 Floating point numbers: R, G, B
	nDst[0] = *(nSrc + 0);
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);

	// 3 32-bit floating point numbers, therefore total size = 3 * sizeof(FLOAT)
	numberOfData = 3;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32G32B32_UINT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType;
	const UINT* nSrc = (UINT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	nDst[0] = *nSrc;
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);

	numberOfData = 3;
	sizeOfDataType = numberOfData * sizeof(UINT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32G32B32_SINT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType;
	const INT* nSrc = (INT*)pSrc;
	INT* nDst = (INT*)pDst;

	nDst[0] = *nSrc;
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);

	numberOfData = 3;
	sizeOfDataType = numberOfData * sizeof(INT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32G32_TYPELESS(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 8);
	memcpy((nDst + 0), (nSrc + 0), 4);
	memcpy((nDst + 4), (nSrc + 4), 4);

	numberOfData = 2;
	sizeOfDataType = numberOfData * 4;
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32G32_FLOAT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType;
	const FLOAT* nSrc = (FLOAT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = *nSrc;
	nDst[1] = *(nSrc + 1);

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32G32_UINT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType;
	const UINT* nSrc = (UINT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	nDst[0] = *nSrc;
	nDst[1] = *(nSrc + 1);

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(UINT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32G32_SINT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType;
	const INT* nSrc = (INT*)pSrc;
	INT* nDst = (INT*)pDst;

	nDst[0] = *nSrc;
	nDst[1] = *(nSrc + 1);

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(INT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32_TYPELESS(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 4);
	memcpy((nDst + 0), (nSrc + 0), 4);

	numberOfData = 1;
	sizeOfDataType = numberOfData * 4;
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_D32_FLOAT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType;
	const FLOAT* nSrc = (FLOAT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = *nSrc;

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32_FLOAT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType;
	const FLOAT* nSrc = (FLOAT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = *nSrc;

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32_UINT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType;
	const UINT* nSrc = (UINT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	nDst[0] = *nSrc;

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(UINT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R32_SINT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType;
	const INT* nSrc = (INT*)pSrc;
	INT* nDst = (INT*)pDst;

	nDst[0] = *nSrc;

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(INT);
	return sizeOfDataType;
}

// -------------------------------------------- 16 bit -------------------------------------------
DWORD D3DTypesDatabase::dt_R16G16B16A16_TYPELESS(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 16);
	memcpy(nDst, nSrc, 2);
	memcpy(nDst+4, nSrc+2, 2);
	memcpy(nDst+8, nSrc+4, 2);
	memcpy(nDst+12, nSrc+6, 2);

	numberOfData = 4;
	sizeOfDataType = numberOfData * 4;
	return sizeOfDataType;
}

// This one requires converting between a USHORT which is a 2 byte floating point number
// to a 4 byte FLOAT. We'll use the 4 byte float in the output declaration which will then
// be used in the resulting OBJ file if necessary though most likely not.
DWORD D3DTypesDatabase::dt_R16G16B16A16_FLOAT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const USHORT* nSrc = (USHORT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = USHORT_to_FLOAT(*(nSrc));
	nDst[1] = USHORT_to_FLOAT(*(nSrc + 1));
	nDst[2] = USHORT_to_FLOAT(*(nSrc + 2));
	nDst[3] = USHORT_to_FLOAT(*(nSrc + 3));

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

// Converting between Unsigned Normalised FLOAT [0, 1] to FLOAT
// The conversion is as such: f = c / 2^b - 1 where c = UNORM, f = FLOAT and b = #bits = 16 in this case
// so f = c / 65535.0 with infinite precision
// DirectX has this: The starting n-bit value is converted to float (0.0f, 1.0f, 2.0f, etc.) and then divided by (2ⁿ-1).
// https://learn.microsoft.com/en-us/windows/win32/direct3d10/d3d10-graphics-programming-guide-resources-data-conversion
// 
// EXTRA:
// https://fgiesen.wordpress.com/2024/11/06/exact-unorm8-to-float/ Shows UNORM8 -> FLOAT
// https://fgiesen.wordpress.com/2024/12/24/unorm-and-snorm-to-float-hardware-edition/ Shows UNORM16 -> FLOAT
DWORD D3DTypesDatabase::dt_R16G16B16A16_UNORM(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	// This is required to sift through the bits of the data
	UINT mask = *nSrc;

	// First 16 bits - Simple 0xFFFF has all lowest 16 bits set to 1,
	// Bitwise AND will then obtain the last 8 bits from nSrc
	nDst[0] = (FLOAT)(mask & 0xFFFF) / 65535;

	// Second 16 bits - Must shift right by 16 to obtain the bits from 16 - 32
	// From there on, shift by multiples of 16 each time to obtain each byte
	nDst[1] = (FLOAT)(mask >> 16) / 65535;
	
	// Can't just left shift by 32 or 48 as tried before: UINT only is 32 bits so it
	// would shift all bits to left making the UINT = 0x0
	// Need to add 1 to pointer to move to second pair of 32 bits (B16A16) of R16G16B16A16_UNORM
	mask = *(nSrc + 1);
	nDst[2] = (FLOAT)(mask & 0xFFFF) / 65535;
	nDst[3] = (FLOAT)(mask >> 16) / 65535;

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16G16B16A16_UINT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const USHORT* nSrc = (USHORT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	nDst[0] = (UINT)(*(nSrc));
	nDst[1] = (UINT)(*(nSrc + 1));
	nDst[2] = (UINT)(*(nSrc + 2));
	nDst[3] = (UINT)(*(nSrc + 3));

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(UINT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16G16B16A16_SNORM(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	// UINT = Unsigned Int - 4 bytes no significant bit (32 bits)
	// Important to use UINT: all 8 bits are used for absolute value vs. MSB used for sign
	UINT currentNumber = *(nSrc);

	INT signExtended[2];
	// SNORM16 = 16 bit INT. UINT = 32 bits, INT = 32 bits
	// So, INT has 31 bits for absolute value and 1 bit to indicate signage
	// Need to use UINT as an initial pointer to obtain full 8 bits of value
	// Shift by 16 bits left, now the eighth bit is at MSB, convert to INT
	// and now we have signage. Shift back right 16 bits and now, we have
	// correct INT value for SNORM. Convert to FLOAT and success.
	// Mask is 0xffff0000 as "last" 16 bits are all 1.
	signExtended[0] = (INT)(currentNumber << 16) >> 16;
	signExtended[1] = (INT)(currentNumber & 0xffff0000) >> 16;
	nDst[0] = SNORM_to_FLOAT(signExtended[0], 32767);
	nDst[1] = SNORM_to_FLOAT(signExtended[1], 32767);

	// For subsequent numbers, can't shift by more than 16 bits in this case since
	// UINT is only 32 bits, shifting by 32 bits would make all bits 0. So need
	// to instead, shift pointer by 1 unlike with R8G8B8A8_SNORM
	currentNumber = *(nSrc + 1);
	signExtended[0] = (INT)(currentNumber << 16) >> 16;
	signExtended[1] = (INT)(currentNumber & 0xffff0000) >> 16;
	nDst[2] = SNORM_to_FLOAT(signExtended[0], 32767);
	nDst[3] = SNORM_to_FLOAT(signExtended[1], 32767);

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16G16B16A16_SINT(const void* pSrc, void* pDst, DWORD& numberOfData) {
	DWORD sizeOfDataType = 0;
	const SHORT* nSrc = (SHORT*)pSrc;
	INT* nDst = (INT*)pDst;

	nDst[0] = (INT)(*(nSrc));
	nDst[1] = (INT)(*(nSrc + 1));
	nDst[2] = (INT)(*(nSrc + 2));
	nDst[3] = (INT)(*(nSrc + 3));

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(INT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16G16_TYPELESS(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 8);
	memcpy(nDst, nSrc, 2);
	memcpy(nDst + 4, nSrc + 2, 2);

	numberOfData = 2;
	sizeOfDataType = numberOfData * 4;
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16G16_FLOAT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType;
	const USHORT* nSrc = (USHORT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = USHORT_to_FLOAT(*nSrc);
	nDst[1] = USHORT_to_FLOAT(*(nSrc + 1));

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16G16_UNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	// This is required to sift through the bits of the data
	UINT mask = *nSrc;

	// First 16 bits - Simple 0xFFFF has all lowest 16 bits set to 1,
	// Bitwise AND will then obtain the last 8 bits from nSrc
	nDst[0] = (FLOAT)(mask & 0xFFFF) / 65535;

	// Second 16 bits - Must shift right by 16 to obtain the bits from 16 - 32
	// From there on, shift by multiples of 16 each time to obtain each byte
	nDst[1] = (FLOAT)(mask >> 16) / 65535;

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16G16_UINT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	// Obtain each component using masking and bit shifts. Simple.
	// Also because we can't use pointers to move between the components
	// SAD D:
	UINT mask = *nSrc;
	nDst[0] = (FLOAT)(mask & 0xFFFF);
	nDst[1] = (FLOAT)(mask >> 16);

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(UINT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16G16_SNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;
	UINT currentNumber = *(nSrc);

	// Same thing as R16G16B16A16_SNORM. But only have two components 
	// so no need to move pointer by 1
	INT signExtended[2];
	signExtended[0] = (INT)(currentNumber << 16) >> 16;
	signExtended[1] = (INT)(currentNumber & 0xffff0000) >> 16;
	nDst[0] = SNORM_to_FLOAT(signExtended[0], 32767);
	nDst[1] = SNORM_to_FLOAT(signExtended[1], 32767);

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16G16_SINT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	INT* nDst = (INT*)pDst;

	// Obtain each component using masking and bit shifts. Simple.
	// Also because we can't use pointers to move between the components
	// SAD D:
	UINT mask = *nSrc;
	nDst[0] = (INT)(mask << 16) >> 16;
	nDst[1] = (INT)(mask & 0xffff0000) >> 16;

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(INT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16_TYPELESS(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 4);
	memcpy(nDst, nSrc, 2);

	numberOfData = 1;
	sizeOfDataType = numberOfData * 4;
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16_FLOAT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType;
	const USHORT* nSrc = (USHORT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = USHORT_to_FLOAT(*nSrc);

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16_UNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	// USHORT because there's only one R16 component rather than UINT which is unnecessary
	const USHORT* nSrc = (USHORT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	// Convert unsigned short -> unsigned int (16 bits) -> (32 bits)
	USHORT ipt = *nSrc;
	UINT mask = (UINT)ipt;

	// Now can use 16 bit mask and divide to obtain correct Float value
	nDst[0] = (FLOAT)(mask & 0xFFFF) / 65535;

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

//DWORD D3DTypesDatabase::dt_D16_UNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
//{
//	return 0;
//}

DWORD D3DTypesDatabase::dt_R16_UINT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const USHORT* nSrc = (USHORT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	// Again, same as with R16_UNORM - convert USHORT to UINT and then mask
	USHORT ipt = *(nSrc);
	UINT mask = (UINT)ipt;

	// Obtain each component using masking and bit shifts. Simple.
	// Also because we can't use pointers to move between the components
	// SAD D:
	nDst[0] = (FLOAT)(mask & 0xFFFF);

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(UINT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16_SNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const USHORT* nSrc = (USHORT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	USHORT ipt = *(nSrc);
	UINT currentNumber = (UINT)ipt;

	// Same thing as R16G16B16A16_SNORM. But only have two components 
	// so no need to move pointer by 1
	INT signExtended[1];
	signExtended[0] = (INT)(currentNumber << 16) >> 16;
	nDst[0] = SNORM_to_FLOAT(signExtended[0], 32767);

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R16_SINT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const USHORT* nSrc = (USHORT*)pSrc;
	INT* nDst = (INT*)pDst;

	// Same as above
	USHORT ipt = *(nSrc);
	UINT mask = (UINT)ipt;

	// Obtain each component using masking and bit shifts. Simple.
	// Also because we can't use pointers to move between the components
	// SAD D:
	nDst[0] = (INT)(mask << 16) >> 16;

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(INT);
	return sizeOfDataType;
}

// --------------------------------------------- 8 bit -------------------------------------------

DWORD D3DTypesDatabase::dt_R8G8B8A8_TYPELESS(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 16);
	memcpy(nDst, nSrc, 1);
	memcpy(nDst + 4, nSrc + 1, 1);
	memcpy(nDst + 8, nSrc + 2, 1);
	memcpy(nDst + 12, nSrc + 3, 1);

	numberOfData = 4;
	sizeOfDataType = numberOfData * 4;
	return sizeOfDataType;
}

// UNORM8 Conversion, See above for UNORM16 conversion and links to posts about converting between UNORM8 and FLOAT32
// DirectX does it as such: The starting n-bit value is converted to float (0.0f, 1.0f, 2.0f, etc.) and then divided by (2ⁿ-1).
// R8G8B8A8_UNORM has R at lowest 8 bits and A at highest 8 bits, mask to obtain first 8 bits and then divide by 255
// https://learn.microsoft.com/en-us/windows/win32/direct3d10/d3d10-graphics-programming-guide-resources-data-conversion
DWORD D3DTypesDatabase::dt_R8G8B8A8_UNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;
	
	// This is required to sift through the bits of the data
	UINT mask = *nSrc;

	// First 8 bits - Simple 0xFF has all lowest 8 bits set to 1,
	// Bitwise AND will then obtain the last 8 bits from nSrc
	nDst[0] = (FLOAT)(mask & 0xFF) / 255;

	// Second 8 bits - Must shift right by 8 to obtain the bits from 8 - 16
	// From there on, shift by multiples of 8 each time to obtain each byte
	nDst[1] = (FLOAT)((mask >> 8) & 0xFF) / 255;
	nDst[2] = (FLOAT)((mask >> 16) & 0xFF) / 255;
	nDst[3] = (FLOAT)(mask >> 24) / 255;

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

//DWORD D3DTypesDatabase::dt_R8G8B8A8_UNORM_SRGB(const void* pSrc, void* pDst, DWORD& numberOfData)
//{
//	return 0;
//}

DWORD D3DTypesDatabase::dt_R8G8B8A8_UINT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	// Can't use USHORT as pointer. 16 bits too long
	// Need to use 8 bits somehow...? MASKING and BIT SHIFTS!!! :D again...
	UINT currentInput = *nSrc;
	nDst[0] = currentInput & 0xff;
	nDst[1] = (currentInput >> 8) & 0xff;
	nDst[2] = (currentInput >> 16) & 0xff;

	// Don't need mask of 0xff since bit shift by 24 will let the left most bits be 0 anyway
	nDst[3] = (currentInput >> 24);

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(UINT);
	return sizeOfDataType;
}

// Typical R8G8B8A8_SNORM value looks like this: 32 bits, R8: 8 bits - 10000000, G8: 8 bits - 10000000, B8: 8 bits - 10000000, A8: 8 bits - 10000000 
// SNORM = Signed normalised integer, conversion rule: most negative value 10000000 = -1.0f, every other value: c * 1/2^(n-1)-1
// https://learn.microsoft.com/en-us/windows/win32/direct3d10/d3d10-graphics-programming-guide-resources-data-conversion
// https://github.com/metarutaiga/DXSDK/blob/master/D3DX_DXGIFormatConvert.inl#L527
DWORD D3DTypesDatabase::dt_R8G8B8A8_SNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	// UINT = Unsigned Int - 4 bytes no significant bit
	// Important to use UINT: all 8 bits are used for absolute value vs. MSB used for sign
	UINT currentNumber = *(nSrc);

	INT signExtended[4];
	// SNORM8 = 8 bit INT. UINT = 32 bits, INT = 32 bits
	// So, INT has 31 bits for absolute value and 1 bit to indicate signage
	// Need to use UINT as an initial pointer to obtain full 8 bits of value
	// Shift by 24 bits left, now the eighth bit is at MSB, convert to INT
	// and now we have signage. Shift back right 24 bits and now, we have
	// correct INT value for SNORM. Convert to FLOAT and success.
	signExtended[0] = (INT)(currentNumber << 24) >> 24;
	signExtended[1] = (INT)((currentNumber << 16) & 0xff000000) >> 24;
	signExtended[2] = (INT)((currentNumber << 8) & 0xff000000) >> 24;
	signExtended[3] = (INT)(currentNumber & 0xff000000) >> 24;
	nDst[0] = SNORM_to_FLOAT(signExtended[0], 127);
	nDst[1] = SNORM_to_FLOAT(signExtended[1], 127);
	nDst[2] = SNORM_to_FLOAT(signExtended[2], 127);
	nDst[3] = SNORM_to_FLOAT(signExtended[3], 127);

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8G8B8A8_SINT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const UINT* nSrc = (UINT*)pSrc;
	INT* nDst = (INT*)pDst;
	UINT currentInput = *nSrc;

	// Same as above, shift R by 24 left to get MSB at bit 32,
	// then shift back. Continue along each component and mask as well
	nDst[0] = (INT)(currentInput << 24) >> 24;
	nDst[1] = (INT)((currentInput << 16) & 0xff000000) >> 24;
	nDst[2] = (INT)((currentInput << 8) & 0xff000000) > 24;
	nDst[3] = (INT)(currentInput & 0xff000000) >> 24;

	numberOfData = 4;
	sizeOfDataType = numberOfData * sizeof(INT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8G8_TYPELESS(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 8);
	memcpy(nDst, nSrc, 1);
	memcpy(nDst + 4, nSrc + 4, 1);

	numberOfData = 2;
	sizeOfDataType = numberOfData * 4;
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8G8_UNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const USHORT* nSrc = (USHORT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	// This is required to sift through the bits of the data
	USHORT ipt = *nSrc;
	UINT mask = (UINT)ipt;

	// First 8 bits - Simple 0xFF has all lowest 8 bits set to 1,
	// Bitwise AND will then obtain the last 8 bits from nSrc
	nDst[0] = (FLOAT)(mask & 0xFF) / 255;

	// Second 8 bits - Must shift right by 8 to obtain the bits from 8 - 16
	// From there on, shift by multiples of 8 each time to obtain each byte
	nDst[1] = (FLOAT)((mask >> 8) & 0xFF) / 255;

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8G8_UINT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const USHORT* nSrc = (USHORT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	// Can't use USHORT as pointer. 16 bits too long
	// Need to use 8 bits somehow...? MASKING and BIT SHIFTS!!! :D again...
	// So use UINT again
	USHORT ipt = *nSrc;
	UINT currentInput = (UINT)ipt;
	nDst[0] = currentInput & 0xff;
	nDst[1] = (currentInput >> 8) & 0xff;

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(UINT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8G8_SNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const USHORT* nSrc = (USHORT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;
	
	USHORT ipt = *nSrc;
	UINT currentNumber = (UINT)ipt;

	INT signExtended[2];
	signExtended[0] = (INT)(currentNumber << 24) >> 24;
	signExtended[1] = (INT)((currentNumber << 16) & 0xff000000) >> 24;
	nDst[0] = SNORM_to_FLOAT(signExtended[0], 127);
	nDst[1] = SNORM_to_FLOAT(signExtended[1], 127);

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8G8_SINT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const USHORT* nSrc = (USHORT*)pSrc;
	INT* nDst = (INT*)pDst;
	USHORT ipt = *nSrc;
	UINT currentInput = (UINT)ipt;

	// Same as above, shift R by 24 left to get MSB at bit 32,
	// then shift back. Continue along each component and mask as well
	nDst[0] = (INT)(currentInput << 24) >> 24;
	nDst[1] = (INT)((currentInput << 16) & 0xff000000) >> 24;

	numberOfData = 2;
	sizeOfDataType = numberOfData * sizeof(INT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8_TYPELESS(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 4);
	memcpy(nDst, nSrc, 1);

	numberOfData = 1;
	sizeOfDataType = numberOfData * 4;
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8_UNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	// This is required to sift through the bits of the data
	BYTE ipt = *nSrc;
	UINT mask = (UINT)ipt;

	// First 8 bits - Simple 0xFF has all lowest 8 bits set to 1,
	// Bitwise AND will then obtain the last 8 bits from nSrc
	nDst[0] = (FLOAT)(mask & 0xFF) / 255;

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8_UINT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	UINT* nDst = (UINT*)pDst;

	// Can't use USHORT as pointer. 16 bits too long
	// Need to use 8 bits somehow...? MASKING and BIT SHIFTS!!! :D again...
	// So use UINT again
	BYTE ipt = *nSrc;
	UINT currentInput = (UINT)ipt;
	nDst[0] = currentInput & 0xff;

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(UINT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8_SNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;
	BYTE ipt = *nSrc;
	UINT currentNumber = (UINT)ipt;

	INT signExtended = (INT)(currentNumber << 24) >> 24;
	nDst[0] = SNORM_to_FLOAT(signExtended, 127);

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(FLOAT);
	return sizeOfDataType;
}

DWORD D3DTypesDatabase::dt_R8_SINT(const void* pSrc, void* pDst, DWORD& numberOfData)
{
	DWORD sizeOfDataType = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	INT* nDst = (INT*)pDst;
	BYTE ipt = *nSrc;
	UINT currentInput = (UINT)ipt;

	// Same as above, shift R by 24 left to get MSB at bit 32,
	// then shift back. Continue along each component and mask as well
	nDst[0] = (INT)(currentInput << 24) >> 24;

	numberOfData = 1;
	sizeOfDataType = numberOfData * sizeof(INT);
	return sizeOfDataType;
}

//DWORD D3DTypesDatabase::dt_A8_UNORM(const void* pSrc, void* pDst, DWORD& numberOfData)
//{
//	return 0;
//}
