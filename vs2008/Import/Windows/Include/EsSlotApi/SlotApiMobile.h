#ifndef _SLOTLIB_MOBILE_H_
#define _SLOTLIB_MOBILE_H_

#include <EsTypeDef.h>
#include <EsSlotApi/EsSlotApi.h>


typedef u4 (*FunSendApdu) (const u1* pu1Send, u4 u4SendLen, u1* pu1Recv, u4* pu4RecvLen);

class ISlotApiMobile
{
public:
    ISlotApiMobile();
    virtual ~ISlotApiMobile();

    // 构造对象
    static ISlotApiMobile*   CreateInstance(FunSendApdu pfunSendCmd);

    // 通知设备插入后，仅以下第1组函数可用：SlotList,SlotInitToken,SlotGetInfo,SlotGetTokenInfo,SlotGetMediaId
    virtual u4  SlotNotifyInsert() = 0;
    // 调用SlotPrepareToken后所有功能可用
    virtual u4  SlotPrepareToken() = 0;
    // 通知拔除后，所有功能不可用
    virtual u4  SlotNotifyRemove() = 0;


    virtual u4  SlotList(IN u4 u4ListType, OUT u4 *pu4SlotIdList, OUT u4* pu4SlotIdCount) = 0;
    virtual u4  SlotLock() = 0;
    virtual u4  SlotUnlock() = 0;
    virtual u4  SlotInitToken(IN const BlkInitTokenParam* pblkInitTokenParam) = 0;
    virtual u4  SlotGetInfo(OUT BlkSlotInfo* pblkSlotInfo) = 0;
    virtual u4  SlotGetTokenInfo(OUT BlkTokenInfo* pblkTokenInfo) = 0;
    virtual u4  SlotGetMediaId(u1* pszMediaId, u4* pu4MediaIdLen) = 0;

    virtual u4  SlotGenRand(OUT void* pvRand, IN u4 u4Len) = 0;
    virtual u4  SlotGetProtectKeyInfo(OUT BlkProtectKeyInfo* pblkProtectKeyInfo) = 0;
    virtual u4  SlotUpdateProtectKey(IN BlkUpdateProtectKeyParam* pblkUpdataProtectKeyParam) = 0;
    virtual u4  SlotChangeLabel(IN const char* pszLabel) = 0;

    virtual u4  SlotCntFind(IN const char* szCntName, OUT u4* pu4CntId) = 0;
    virtual u4  SlotCntCreate(IN const char* szCntName, OUT u4* pu4CntId) = 0;
    virtual u4  SlotCntDelete(IN u4 u4CntId, IN u4 u4DeleteFlag) = 0;
    virtual u4  SlotCntList(OUT u4* pu4CntList, IN OUT u4* pu4CntNum) = 0;

    virtual u4  SlotCntGenKey(IN u4 u4CntId, IN u4 u4KeySpec, IN u4 u4AlgId, IN u4 u4ModBits, IN u4 u4KeyPairUseLimit) = 0;

    virtual u4  SlotCntWriteCert(IN u4 u4CntId, IN u4 u4KeySpec, IN const u1* pu1Cert, IN u4 u4CertLen) = 0;
    virtual u4  SlotCntReadCert(IN u4 u4CntId, IN u4 u4KeySpec, OUT u1* pu1Cert, IN OUT u4* pu4CertLen) = 0;
    virtual u4  SlotCntGetInfo(IN u4 u4CntId, OUT BlkCntInfo *pblkCntInfo) = 0;
    virtual u4  SlotCntReadPubKey(IN u4 u4CntId, IN u4 u4KeySpec, OUT BlkAsymKey* pblkAsymKey) = 0;

    virtual u4  SlotCntReadEncryptedPubKey(
        IN BlkPubKeyList * pblkPubKeyList, 
        IN BlkReadEncryptedPubKeyParam* pblkReadParam, 
        OUT u1* pu1EncryptedPubKey, IN OUT u4* pu4EncryptedPubKeyLen) = 0;
    virtual u4  SlotCntWritePubKey(IN u4 u4CntId, IN u4 u4KeySpec, IN const BlkAsymKey* pblkAsymKey) = 0;
    virtual u4  SlotCntWritePriKey(IN u4 u4CntId, IN u4 u4KeySpec, IN const BlkAsymKey* pblkAsymKey) = 0;

    virtual u4  SlotCntEnc(IN u4 u4CntId, IN u4 u4KeySpec, IN u4 u4FinalFlag, 
        IN const void* pvInput, IN u4 u4InputLen, 
        OUT void* pvOutput, IN OUT u4* pu4OutputLen) = 0;
    virtual u4  SlotCntDec(IN u4 u4CntId, IN u4 u4KeySpec, IN u4 u4FinalFlag, 
        IN const void* pvInput, IN u4 u4InputLen, 
        OUT void* pvOutput, IN OUT u4* pu4OutputLen) = 0;
    virtual u4  SlotCntSignHash(IN u4 u4CntId, IN u4 u4KeySpec, IN u4 u4HashHandle, OUT void* pvSignature, IN OUT u4* pu4SignatureLen) = 0;
    virtual u4  SlotVerifySignHash(IN BlkAsymKey*pblkAsymKey, IN u4 u4HashHandle, IN const void* pvSignature, IN u4 u4SignatureLen) = 0;

    virtual u4  SlotVerifyPin(IN u4 u4PinType, IN const u1* pu1Pin, IN u4 u4PinLen) = 0;
    virtual u4  SlotChangePin(IN u4 u4PinType, IN const u1* pu1OldPin, IN u4 u4OldPinLen, IN const u1* pu1NewPin, IN u4 u4NewPinLen) = 0;
    virtual u4  SlotUnblockPin(IN const u1* pu1AdminPin, IN u4 u4AdminPinLen, IN const u1* pu1UserPin, IN u4 u4UserPinLen) = 0;

    virtual u4  SlotHashInit(IN u4 u4HashAlgId, OUT u4* pu4HashHandle) = 0;
    virtual u4  SlotHashData(IN u4 u4HashHandle, IN const void* pvData, IN u4 u4DataLen, IN u4 u4FinalFlag) = 0;
    virtual u4  SlotHashGetValue(IN u4 u4HashHandle, OUT void* pvHashValue, IN OUT u4* pu4HashValueLen) = 0;
    virtual u4  SlotHashSetValue(IN u4 u4HashHandle, IN void* pvHashValue) = 0;
    virtual u4  SlotHashGetDataType(IN u4 u4HashHandle, OUT u4* pu4HashDataType) = 0;
    virtual u4  SlotHashRelease(IN u4 u4HashHandle) = 0;

    virtual u4  SlotFileCreate(IN const BlkFileInfo* pblkFileInfo, OUT u4* pu4FileHandle) = 0;
    virtual u4  SlotFileDelete(IN u4 u4FileHandle) = 0;
    virtual u4  SlotFileFind(IN u2 u2FileId, OUT u4* pu4FileHandle) = 0;
    virtual u4  SlotFileGetAttr(IN u4 u4FileHandle, OUT BlkFileInfo* pblkFileInfo) = 0;
    virtual u4  SlotFileRead(IN u4 u4FileHandle, OUT void* pvData, IN u4 u4Offset, IN u4 u4ReadSize) = 0;
    virtual u4  SlotFileWrite(IN u4 u4FileHandle, IN const void* pvData, IN u4 u4Offset, IN u4 u4WriteSize) = 0;

    virtual u4  SlotGetCosFeatures(OUT BlkCosFeatures* pblkCosFeatures) = 0;

    virtual u4  SlotFileCreateViaName(const char* szFileName, u4 u4FileSize, u4 u4FileType, u4* pu4FileHandle) = 0;
    virtual u4  SlotFileEnum(u4 u4FileType, u4* pu4FileHandleList, u4* pu4FileNum) = 0;
    virtual u4  SlotFileGetName(u4 u4FileHandle, char* szFileName, u4* pu4FileNameLen) = 0;

    // YuZhi-cfca
    virtual u4 SlotGetCfcaId(OUT u1* pu1CfcaId, OUT u4* pu4CfcaIdLen) = 0;
    virtual u4 SlotGetChipSn(OUT u1* pu1ChipSn, OUT u4* pu4ChipSnLen) = 0;
    virtual u4 SlotGenTempAsymKey(IN u4 u4AlgId, IN u4 u4ModBits, OUT BlkAsymKey* pblkAsymPubKey) = 0;
    virtual u4 SlotCntEnvImportAsymKey(IN u4 u4ProKeyType, IN BlkEnvAsymKey* pblkEnvAsymKey, IN const BlkAsymKey* pblkAsymPubKey) = 0;

    // symmAlg
    virtual u4 SlotSymmInit(IN BlkSymmAlgInit* pblkSymmAlgInit) = 0;
    virtual u4 SlotSymmUpdate(IN u1* pu1DataIn, IN u4 u4DataInLen, OUT u1* pu1DataOut, IN OUT u4 * pu4DataOutLen) = 0;
    virtual u4 SlotSymmFinal(OUT u1* pu1DataOut, IN OUT u4 * pu4DataOutLen) = 0;

    virtual u4 SlotGetPinInfo(u4 u4PinType, u4* pu4MaxRetryCount, u4* pu4LeftRetryCount, ESBOOL* pbDefault) = 0;
    virtual u4 SlotCntGetDevSignature(IN u4 u4CntId, IN u4 u4KeySpec, INOUT BlkDevSignParam* pblkDevSignParam) = 0;
};

#endif