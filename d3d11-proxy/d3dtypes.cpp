#pragma once

#include "pch.h"
#include "d3d11.h"
#include "d3dtypes.h"

//------------------------------------------------------------------------------------------------
//  
//										TYPE PROPERTY OBTAINERS
// 
//------------------------------------------------------------------------------------------------

DWORD D3DTypesDatabase::dp_obtainTypeSize(DXGI_FORMAT format) {
	return 0;
}

//------------------------------------------------------------------------------------------------
//  
//										 TYPE MEMORY DECODERS
// 
//------------------------------------------------------------------------------------------------

DWORD D3DTypesDatabase::decodeAndCopy(DXGI_FORMAT format, const void* pSrc, void* pDst, DWORD& compCnt) {
	// For each DXGI format, decode and obtain correct memory from vertex buffer
	switch (format) {

	case (DXGI_FORMAT_R32G32B32_FLOAT):
		return dt_R32G32B32_FLOAT(pSrc, pDst, compCnt);

	case(DXGI_FORMAT_R16G16B16A16_FLOAT):
		//return dt_R16G16B16A16_FLOAT();
		return 0;
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

// -------------------------------------------- 32 bit -------------------------------------------
DWORD D3DTypesDatabase::dt_R32G32B32A32_TYPELESS(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 16);
	memcpy((nDst + 0), (nSrc + 0), 4);
	memcpy((nDst + 4), (nSrc + 4), 4);
	memcpy((nDst + 8), (nSrc + 8), 4);
	memcpy((nDst + 12), (nSrc + 12), 4);

	compCnt = 4;
	outVal = compCnt * 4;
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32G32B32A32_FLOAT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal = 0;
	const FLOAT* nSrc = (FLOAT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = *(nSrc);
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);
	nDst[3] = *(nSrc + 3);

	compCnt = 4;
	outVal = compCnt * sizeof(FLOAT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32G32B32A32_UINT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal = 0;
	const UINT* nSrc = (UINT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	nDst[0] = *(nSrc);
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);
	nDst[3] = *(nSrc + 3);

	compCnt = 4;
	outVal = compCnt * sizeof(UINT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32G32B32A32_SINT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal = 0;
	const INT* nSrc = (INT*)pSrc;
	INT* nDst = (INT*)pDst;

	nDst[0] = *(nSrc);
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);
	nDst[3] = *(nSrc + 3);

	compCnt = 4;
	outVal = compCnt * sizeof(INT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32G32B32_TYPELESS(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 12);
	memcpy((nDst + 0), (nSrc + 0), 4);
	memcpy((nDst + 4), (nSrc + 4), 4);
	memcpy((nDst + 8), (nSrc + 8), 4);

	compCnt = 3;
	outVal = compCnt * 4;
	return outVal;
}

// Most likely one for POSITION semantic to use
DWORD D3DTypesDatabase::dt_R32G32B32_FLOAT(const void* pSrc, void* pDst, DWORD& compCnt) {
	// Starting Locals - FLOAT because it is 4 bytes = 32 bits
	DWORD outVal = 0;
	const FLOAT* nSrc = (FLOAT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	// 3 Floating point numbers: R, G, B
	nDst[0] = *(nSrc);
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);

	// 3 32-bit floating point numbers, therefore total size = 3 * sizeof(FLOAT)
	compCnt = 3;
	outVal = compCnt * sizeof(FLOAT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32G32B32_UINT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal;
	const UINT* nSrc = (UINT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	nDst[0] = *nSrc;
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);

	compCnt = 3;
	outVal = compCnt * sizeof(UINT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32G32B32_SINT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal;
	const INT* nSrc = (INT*)pSrc;
	INT* nDst = (INT*)pDst;

	nDst[0] = *nSrc;
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);

	compCnt = 3;
	outVal = compCnt * sizeof(INT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32G32_TYPELESS(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 8);
	memcpy((nDst + 0), (nSrc + 0), 4);
	memcpy((nDst + 4), (nSrc + 4), 4);

	compCnt = 2;
	outVal = compCnt * 4;
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32G32_FLOAT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal;
	const FLOAT* nSrc = (FLOAT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = *nSrc;
	nDst[1] = *(nSrc + 1);

	compCnt = 2;
	outVal = compCnt * sizeof(FLOAT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32G32_UINT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal;
	const UINT* nSrc = (UINT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	nDst[0] = *nSrc;
	nDst[1] = *(nSrc + 1);

	compCnt = 2;
	outVal = compCnt * sizeof(UINT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32G32_SINT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal;
	const INT* nSrc = (INT*)pSrc;
	INT* nDst = (INT*)pDst;

	nDst[0] = *nSrc;
	nDst[1] = *(nSrc + 1);

	compCnt = 2;
	outVal = compCnt * sizeof(INT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32_TYPELESS(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal = 0;
	const BYTE* nSrc = (BYTE*)pSrc;
	BYTE* nDst = (BYTE*)pDst;

	memset(nDst, 0, 4);
	memcpy((nDst + 0), (nSrc + 0), 4);

	compCnt = 1;
	outVal = compCnt * 4;
	return outVal;
}

DWORD D3DTypesDatabase::dt_D32_FLOAT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal;
	const FLOAT* nSrc = (FLOAT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = *nSrc;

	compCnt = 1;
	outVal = compCnt * sizeof(FLOAT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32_FLOAT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal;
	const FLOAT* nSrc = (FLOAT*)pSrc;
	FLOAT* nDst = (FLOAT*)pDst;

	nDst[0] = *nSrc;

	compCnt = 1;
	outVal = compCnt * sizeof(FLOAT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32_UINT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal;
	const UINT* nSrc = (UINT*)pSrc;
	UINT* nDst = (UINT*)pDst;

	nDst[0] = *nSrc;

	compCnt = 1;
	outVal = compCnt * sizeof(UINT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R32_SINT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal;
	const INT* nSrc = (INT*)pSrc;
	INT* nDst = (INT*)pDst;

	nDst[0] = *nSrc;

	compCnt = 1;
	outVal = compCnt * sizeof(INT);
	return outVal;
}

// -------------------------------------------- 16 bit -------------------------------------------

DWORD D3DTypesDatabase::dt_R16G16B16A16_TYPELESS(const void* pSrc, void* pDst, DWORD& compCnt) {
	return 0;
}

float D3DTypesDatabase::USHORT_to_FLOAT(USHORT u) {
	return 0.f;
}

DWORD D3DTypesDatabase::dt_R16G16B16A16_FLOAT(const void* pSrc, void* pDst, DWORD& compCnt) {
	DWORD outVal = 0;
	const USHORT* nSrc = (USHORT*)pSrc;
	USHORT* nDst = (USHORT*)pDst;

	nDst[0] = *(nSrc);
	nDst[1] = *(nSrc + 1);
	nDst[2] = *(nSrc + 2);
	nDst[3] = *(nSrc + 3);

	compCnt = 4;
	outVal = compCnt * sizeof(FLOAT);
	return outVal;
}

DWORD D3DTypesDatabase::dt_R16G16B16A16_UNORM(const void* pSrc, void* pDst, DWORD& compCnt) {
	return 0;
}

DWORD D3DTypesDatabase::dt_R16G16B16A16_UINT(const void* pSrc, void* pDst, DWORD& compCnt) {
	return 0;
}

DWORD D3DTypesDatabase::dt_R16G16B16A16_SNORM(const void* pSrc, void* pDst, DWORD& compCnt) {
	return 0;
}

DWORD D3DTypesDatabase::dt_R16G16B16A16_SINT(const void* pSrc, void* pDst, DWORD& compCnt) {
	return 0;
}

DWORD D3DTypesDatabase::dt_R16G16_TYPELESS(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R16G16_FLOAT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R16G16_UNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R16G16_UINT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R16G16_SNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R16G16_SINT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}

DWORD D3DTypesDatabase::dt_R16_TYPELESS(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R16_FLOAT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R16_UNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_D16_UNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R16_UINT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R16_SNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R16_SINT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}

// --------------------------------------------- 8 bit -------------------------------------------

DWORD D3DTypesDatabase::dt_R8G8B8A8_TYPELESS(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8G8B8A8_UNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8G8B8A8_UNORM_SRGB(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8G8B8A8_UINT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8G8B8A8_SNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8G8B8A8_SINT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8G8_TYPELESS(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8G8_UNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8G8_UINT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8G8_SNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8G8_SINT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8_TYPELESS(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8_UNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8_UINT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8_SNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_R8_SINT(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
DWORD D3DTypesDatabase::dt_A8_UNORM(const void* pSrc, void* pDst, DWORD& compCnt)
{
	return 0;
}
