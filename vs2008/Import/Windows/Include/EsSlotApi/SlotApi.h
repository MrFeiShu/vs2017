#ifndef _SLOTAPI_H_
#define _SLOTAPI_H_

#if defined(__cplusplus)
extern "C"
{
#endif

u4 CALL_TYPE SlotLibInit(void);
u4 CALL_TYPE SlotLibFinal(void);

u4 CALL_TYPE SlotList(IN u4 u4ListType, OUT u4 *pu4SlotIdList, OUT u4* pu4SlotIdCount);
u4 CALL_TYPE SlotLock(IN u4 u4SlotId);
u4 CALL_TYPE SlotUnlock(IN u4 u4SlotId);
u4 CALL_TYPE SlotInitToken(IN u4 u4SlotId, IN const BlkInitTokenParam* pblkInitTokenParam);
u4 CALL_TYPE SlotGetInfo(IN u4 u4SlotId, OUT BlkSlotInfo* pblkSlotInfo);
u4 CALL_TYPE SlotGetTokenInfo(IN u4 u4SlotId, OUT BlkTokenInfo* pblkTokenInfo);
// u4 CALL_TYPE SlotGetMediaId(IN u4 u4SlotId, char* pszMediaId, u4* pu4MediaIdLen);

u4 CALL_TYPE SlotGenRand(IN u4 u4SlotId, OUT void* pvRand, IN u4 u4Len);
u4 CALL_TYPE SlotGetProtectKeyInfo(IN u4 u4SlotId, OUT BlkProtectKeyInfo* pblkProtectKeyInfo);
u4 CALL_TYPE SlotUpdateProtectKey(IN u4 u4SlotId, IN BlkUpdateProtectKeyParam* pblkUpdataProtectKeyParam);
u4 CALL_TYPE SlotChangeLabel(IN u4 u4SlotId, IN const char* pszLabel);

u4 CALL_TYPE SlotRegDevEventCallback(IN u4 u4RegType, IN ESBOOL bIsRegister, IN FunSlotEventRoutine funSlotEventRoutine);

u4 CALL_TYPE SlotCntFind(IN u4 u4SlotId, IN const char* szCntName, OUT u4* pu4CntId);
u4 CALL_TYPE SlotCntCreate(IN u4 u4SlotId, IN const char* szCntName, OUT u4* pu4CntId);
u4 CALL_TYPE SlotCntDelete(IN u4 u4CntId, IN u4 u4DeleteFlag);
u4 CALL_TYPE SlotCntList(IN u4 u4SlotId, OUT u4* pu4CntList, IN OUT u4* pu4CntNum);

u4 CALL_TYPE SlotCntGenKey(IN u4 u4CntId, IN u4 u4KeySpec, IN u4 u4AlgId, IN u4 u4ModBits, IN u4 u4KeyPairUseLimit);
u4 CALL_TYPE SlotCntWriteCert(IN u4 u4CntId, IN u4 u4KeySpec, IN const u1* pu1Cert, IN u4 u4CertLen);
u4 CALL_TYPE SlotCntReadCert(IN u4 u4CntId, IN u4 u4KeySpec, OUT u1* pu1Cert, IN OUT u4* pu4CertLen);
u4 CALL_TYPE SlotCntGetInfo(IN u4 u4CntId, OUT BlkCntInfo *pblkCntInfo);
u4 CALL_TYPE SlotCntReadPubKey(IN u4 u4CntId, IN u4 u4KeySpec, OUT BlkAsymKey* pblkAsymKey);
u4 CALL_TYPE SlotCntReadEncryptedPubKey(IN u4 u4SlotId, 
										IN BlkPubKeyList * pblkPubKeyList, 
										IN BlkReadEncryptedPubKeyParam* pblkReadParam, 
										OUT u1* pu1EncryptedPubKey, IN OUT u4* pu4EncryptedPubKeyLen);
u4 CALL_TYPE SlotCntWritePubKey(IN u4 u4CntId, IN u4 u4KeySpec, IN const BlkAsymKey* pblkAsymKey);
u4 CALL_TYPE SlotCntWritePriKey(IN u4 u4CntId, IN u4 u4KeySpec, IN const BlkAsymKey* pblkAsymKey);

u4 CALL_TYPE SlotCntEnc(IN u4 u4CntId, IN u4 u4KeySpec, IN u4 u4FinalFlag, 
						IN const void* pvInput, IN u4 u4InputLen, 
						OUT void* pvOutput, IN OUT u4* pu4OutputLen);
u4 CALL_TYPE SlotCntDec(IN u4 u4CntId, IN u4 u4KeySpec, IN u4 u4FinalFlag, 
						IN const void* pvInput, IN u4 u4InputLen, 
						OUT void* pvOutput, IN OUT u4* pu4OutputLen);
u4 CALL_TYPE SlotCntSignHash(IN u4 u4CntId, IN u4 u4KeySpec, IN u4 u4HashHandle, OUT void* pvSignature, IN OUT u4* pu4SignatureLen);
u4 CALL_TYPE SlotVerifySignHash(IN u4 u4SlotId, IN BlkAsymKey*pblkAsymKey, IN u4 u4HashHandle, IN const void* pvSignature, IN u4 u4SignatureLen);

u4 CALL_TYPE SlotVerifyPin(IN u4 u4SlotId, IN u4 u4PinType, IN const u1* pu1Pin, IN u4 u4PinLen);
u4 CALL_TYPE SlotChangePin(IN u4 u4SlotId, IN u4 u4PinType, IN const u1* pu1OldPin, IN u4 u4OldPinLen, IN const u1* pu1NewPin, IN u4 u4NewPinLen);
u4 CALL_TYPE SlotUnblockPin(IN u4 u4SlotId, IN const u1* pu1AdminPin, IN u4 u4AdminPinLen, IN const u1* pu1UserPin, IN u4 u4UserPinLen);
u4 CALL_TYPE SlotCachePinVerify(IN u4 u4SlotId);
u4 CALL_TYPE SlotCachePinSet(IN u4 u4SlotId, IN const u1* pu1Pin, IN u4 u4PinLen);
u4 CALL_TYPE SlotCachePinClr(IN u4 u4SlotId);



u4 CALL_TYPE SlotHashInit(IN u4 u4SlotId, IN u4 u4HashAlgId, OUT u4* pu4HashHandle);
u4 CALL_TYPE SlotHashData(IN u4 u4HashHandle, IN const void* pvData, IN u4 u4DataLen, IN u4 u4FinalFlag);
u4 CALL_TYPE SlotHashGetValue(IN u4 u4HashHandle, OUT void* pvHashValue, IN OUT u4* pu4HashValueLen);
u4 CALL_TYPE SlotHashSetValue(IN u4 u4HashHandle, IN void* pvHashValue);
u4 CALL_TYPE SlotHashGetDataType(IN u4 u4HashHandle, OUT u4* pu4HashDataType);
u4 CALL_TYPE SlotHashRelease(IN u4 u4HashHandle);

u4 CALL_TYPE SlotFileCreate(IN u4 u4SlotId, IN const BlkFileInfo* pblkFileInfo, OUT u4* pu4FileHandle);
u4 CALL_TYPE SlotFileDelete(IN u4 u4SlotId, IN u4 u4FileHandle);
u4 CALL_TYPE SlotFileFind(IN u4 u4SlotId, IN u2 u2FileId, OUT u4* pu4FileHandle);
u4 CALL_TYPE SlotFileGetAttr(IN u4 u4SlotId, IN u4 u4FileHandle, OUT BlkFileInfo* pblkFileInfo);
u4 CALL_TYPE SlotFileRead(IN u4 u4SlotId, IN u4 u4FileHandle, OUT void* pvData, IN u4 u4Offset, IN u4 u4ReadSize);
u4 CALL_TYPE SlotFileWrite(IN u4 u4SlotId, IN u4 u4FileHandle, IN const void* pvData, IN u4 u4Offset, IN u4 u4WriteSize);

u4 CALL_TYPE SlotGetCosFeatures(IN u4 u4SlotId, OUT BlkCosFeatures* pblkCosFeatures);
// u4 CALL_TYPE SlotCntSetParam(IN u4 u4CntId, IN u4 u4Param, IN u4 u4Flag, IN const u1* pu1Data);
// u4 CALL_TYPE SlotCntGetParam(IN u4 u4CntId, IN u4 u4Param, IN u4 u4Flag, IN u1* pu1Data, IN OUT u4* pu4DataLen);
    
u4 CALL_TYPE SlotFileCreateViaName(u4 u4SlotId, const char* szFileName, u4 u4FileSize, u4 u4FileType, u4* pu4FileHandle);
u4 CALL_TYPE SlotFileEnum(u4 u4SlotId, u4 u4FileType, u4* pu4FileHandleList, u4* pu4FileNum);
u4 CALL_TYPE SlotFileGetName(u4 u4SlotId, u4 u4FileHandle, char* szFileName, u4* pu4FileNameLen);

// bNeedConfirm = ESTRUE 表示用户需要确认输入
u4 CALL_TYPE SlotUiGetPin(IN u4 u4SlotId, IN u4 u4PinType, IN ESBOOL bNeedConfirm, OUT u1* pu1Pin, IN OUT u4 * pu4PinLen);
u4 CALL_TYPE SlotUiVerifyPin(IN u4 u4SlotId, IN u4 u4PinType, IN BlkVerifyPinContext* pblkVerifyPinContext);
u4 CALL_TYPE SlotUiChangePin(IN u4 u4SlotId, IN u4 u4PinType);
u4 CALL_TYPE SlotUiChangeLabel(IN u4 u4SlotId);
u4 CALL_TYPE SlotUiPrompt(IN u4 u4PromtMsgId, IN u4 u4Param, IN u1* pu1ExtraParam, IN u4 u4ExtraParamLen);
u4 CALL_TYPE SlotUiSelToken(IN OUT u4* pu4SelSlotId);
u4 CALL_TYPE SlotUiUnblockPin(IN u4 u4SlotId);

// 设置中间件界面语言，语言列表在EsCommon.h内
u4 CALL_TYPE SlotUiSetLang(IN u4 u4SlotId);

u4 CALL_TYPE SlotGetCharSetList(IN u4 u4SlotId, OUT EnCharSet * pEnCharSetList, OUT u4* pu4CharSetCount);
u4 CALL_TYPE SlotGetCharSet(IN u4 u4SlotId, OUT EnCharSet* pEnCharSet);
u4 CALL_TYPE SlotSetCharSet(IN u4 u4SlotId, IN EnCharSet enCharSet);

u4 CALL_TYPE SlotGetLangIdList(IN u4 u4SlotId, OUT EnLangId * pEnLangIdList, OUT u4* pu4LangIdCount);
u4 CALL_TYPE SlotGetLangId(IN u4 u4SlotId, IN EnLangId* pEnLangId);
u4 CALL_TYPE SlotSetLangId(IN u4 u4SlotId, IN EnLangId enLangId);


u4 CALL_TYPE SlotSetWarningMsg(IN u4 u4SlotId, IN const char* pszWarningMsg);
// YuZhi-cfca
u4 CALL_TYPE SlotGetCfcaId(IN u4 u4SlotId, OUT u1* pu1CfcaId, OUT u4* pu4CfcaIdLen);
u4 CALL_TYPE SlotGetChipSn(IN u4 u4SlotId, OUT u1* pu1ChipSn, OUT u4* pu4ChipSnLen);
u4 CALL_TYPE SlotGenTempAsymKey(IN u4 u4SlotId, IN u4 u4AlgId, IN u4 u4ModBits, OUT BlkAsymKey* pblkAsymPubKey);
u4 CALL_TYPE SlotCntEnvImportAsymKey(IN u4 u4CntId, IN u4 u4ProKeyType, IN BlkEnvAsymKey* pblkEnvAsymKey, IN const BlkAsymKey* pblkAsymPubKey);

// symmAlg
u4 CALL_TYPE SlotSymmInit(IN u4 u4SlotId, IN BlkSymmAlgInit* pblkSymmAlgInit);

u4 CALL_TYPE SlotSymmUpdate(IN u4 u4SlotId, IN const u1* pu1DataIn, IN u4 u4DataInLen, OUT u1* pu1DataOut, IN OUT u4 * pu4DataOutLen);

u4 CALL_TYPE SlotSymmFinal(IN u4 u4SlotId, OUT u1* pu1DataOut, IN OUT u4 * pu4DataOutLen);

// SM2 KeyAgreement
u4 CALL_TYPE SlotSm2KAGenData(IN u4 u4CntId, IN u4 u4KeySpec, IN u4 u4SymmAlgId, 
							  IN u1* pu1IdA, IN u4 u4IdALen, 
							  OUT BlkAsymKey* pblkTempPubKeyA);

u4 CALL_TYPE SlotSm2KAGenDataAndKey(IN u4 u4CntId, IN u4 u4KeySpec, IN u4 u4SymmAlgId, 
									IN u1* pu1IdA, IN u4 u4IdALen, 
									IN u1* pu1IdB, IN u4 u4IdBLen, 
									IN BlkAsymKey* pblkPubKeyA, IN BlkAsymKey* pblkTempPubKeyA,
									OUT BlkAsymKey* pblkTempPubKeyB);

u4 CALL_TYPE SlotSm2KAGenKey(IN u4 u4SlotId, 
							 IN u1* pu1IdB, IN u4 u4IdBLen, 
							 IN BlkAsymKey* pblkPubKeyB, IN BlkAsymKey* pblkTempPubKeyB);


// PKCS11
#ifndef _SLOT_OBJECT_TYPE_
#define _SLOT_OBJECT_TYPE_
#define SLOT_OBJTYPE_PUB_DATA		0x00000000
#define SLOT_OBJTYPE_CERT			0x00000001
#define SLOT_OBJTYPE_PUB_KEY		0x00000002
#define SLOT_OBJTYPE_PRI_KEY		0x00000003
#define SLOT_OBJTYPE_SECRET_KEY		0x00000004
#define SLOT_OBJTYPE_PRI_DATA		0x00008000
#define SLOT_OBJTYPE_PRI_SECRET_KEY	0x00008004	// PKCS11对象类型，除私有数据、私钥密钥类型外，其他几种都是与CKO_XXX对应
#endif

u4 CALL_TYPE SlotObjectList(IN u4 u4SlotId, IN  ESBOOL bPrivate, OUT u4* pu4ObjectIdList, INOUT u4* pu4ObjectNum);
u4 CALL_TYPE SlotObjectRead(IN u4 u4SlotId, IN u4 u4ObjectId, OUT u1* pu1ObjectAttr, INOUT u4* pu4ObjectAttrLen);
u4 CALL_TYPE SlotObjectWrite(IN u4 u4SlotId, IN u4 u4ObjectId, IN const u1* pu1ObjectAttr, IN u4 u4ObjectAttrLen);
u4 CALL_TYPE SlotObjectCreate(IN u4 u4SlotId, IN u4 u4ObjectType, IN u4 u4ObjectAttrLen, OUT u4* pu4ObjectId);
u4 CALL_TYPE SlotObjectDelete(IN u4 u4SlotId, IN u4 u4ObjectId);
u4 CALL_TYPE SlotObjectGetKeyPairId(IN u4 u4CntId, IN u4 u4KeySpec,OUT u4* pu4ObjectIdPubKey, OUT u4* pu4ObjectIdPriKey, OUT u4* pu4ObjectIdCert);

//zqb:copied frome ios version 2013-10-21 21:19:49
u4 CALL_TYPE SlotLockTimeout(IN u4 u4SlotId, u4 u4Timeout);
u4 CALL_TYPE SlotGetMediaId(IN u4 u4SlotId, OUT u1* pu1MediaId, OUT u4* pu4MediaIdLen);
u4 CALL_TYPE SlotGetPinInfo(IN u4 u4SlotId, u4 u4PinType, u4* pu4MaxRetryCount, u4* pu4LeftRetryCount, ESBOOL* pbDefault);


u4 CALL_TYPE SlotCntGetDevSignature(IN u4 u4CntId, IN u4 u4KeySpec, INOUT BlkDevSignParam* pblkDevSignParam);

u4 CALL_TYPE SlotSendApdu(IN u4 u4SlotId, IN const void* pvApdu, IN u4 u4ApduLen, OUT void* pvResp, INOUT u4* pu4RespLen);

u4 CALL_TYPE SlotSetFontType(IN u4 u4SlotId, IN EnFontType enFontType);
u4 CALL_TYPE SlotGetFontType(IN u4 u4SlotId, OUT EnFontType* pEnFontType);

u4 CALL_TYPE SlotPrepareToken(IN u4 u4SlotId);
u4 CALL_TYPE SlotListDev(IN u4 u4DevType, OUT char* pszDevList, INOUT u4* pu4ListSize);
u4 CALL_TYPE SlotConnectDev(IN u4 u4DevType, IN const char* pszDevName, OUT u4* pu4SlotId);
u4 CALL_TYPE SlotDisconnectDev(IN u4 u4SlotId);
u4 CALL_TYPE SlotNotifyEvent(IN u4 u4SlotId, IN u4 u4EventType, INOUT void* pvParam, IN u4 u4Size);

u4 CALL_TYPE SlotGetParam(IN u4 u4SlotId,  OUT BlkSlotParam* pblkSlotParam);
u4 CALL_TYPE SlotSetParam(IN u4 u4SlotId, IN const BlkSlotParam* pblkSlotParam);
#if defined(__cplusplus)
};
#endif

#endif
