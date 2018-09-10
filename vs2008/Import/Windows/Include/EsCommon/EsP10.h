#ifndef _ESP10_H_
#define _ESP10_H_
#ifdef __cplusplus
extern "C"
{
#endif
u4 CALL_TYPE EsP10GenRequestInfo(IN const BlkAsymKey* pblkAsymKey, 
								 IN const BlkAsymKey* pblkAsymKeyTemp,
								 IN const char* pszDn, 
								 OUT void* pvRequestInfo, 
								 INOUT u4* pu4RequestInfoLen);
u4 CALL_TYPE EsP10GenRequest(IN const void* pvRequstInfo, 
							 IN u4 u4RequestInfoLen, 
							 IN const void* pvSignature, 
							 IN u4 u4HashAlgId, 
							 OUT void* pvRequest, 
							 INOUT u4* pu4RequestLen);

u4 CALL_TYPE EsP10ParseRequest(IN const void* pvRequest, 
							   IN u4 u4RequestLen, 
							   OUT BlkAsymKey* pblkAsymKeySign,
							   OUT BlkAsymKey* pblkAsymTemp,
							   OUT char* pszDn, 
							   INOUT u4* pu4DnLen);
#ifdef __cplusplus
}
#endif
#endif
