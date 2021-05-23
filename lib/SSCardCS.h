#ifndef SSCARDCS_H
#define SSCARDCS_H
//#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/********************获取设备信息********************/
long WINAPI iGetDeviceInfo(char* pOutInfo);

/********************读基本信息********************/
long WINAPI iReadCardBas(int iType, char* pOutInfo);
long WINAPI iReadCardBas_HSM_Step1(int iType, char* pOutInfo);
long WINAPI iReadCardBas_HSM_Step2(char *pKey, char* pOutInfo);

/********************通用读卡********************/
long WINAPI iReadCard (int iType, int iAuthType, char* pCardInfo, char* pFileAddr, char* pOutInfo);
long WINAPI iReadCard_HSM_Step1(int iType, char* pCardInfo, char* pFileAddr, char* pOutInfo);
long WINAPI iReadCard_HSM_Step2(char* pKey, char* pOutInfo);

/********************通用写卡********************/
long WINAPI iWriteCard (int iType, char* pCardInfo, char* pFileAddr, char* pWriteData, char* pOutInfo);
long WINAPI iWriteCard_HSM_Step1(int iType, char* pCardInfo, char* pFileAddr, char* pOutInfo);
long WINAPI iWriteCard_HSM_Step2(char* pKey, char* pWriteData, char* pOutInfo);

/********************PIN校验********************/
long WINAPI iVerifyPIN(int iType, char* pOutInfo);

/********************PIN修改********************/
long WINAPI iChangePIN(int iType, char* pOutInfo);

/********************PIN重置********************/
long WINAPI iReloadPIN(int iType, char* pCardInfo, char* pOutInfo);
long WINAPI iReloadPIN_HSM_Step1(int iType, char* pCardInfo, char* pOutInfo);
long WINAPI iReloadPIN_HSM_Step2(char* pKey, char* pOutInfo);
long WINAPI iReloadPIN_HSM_Step3(char* pKey, char* pOutInfo);

/********************PIN解锁********************/
long WINAPI iUnblockPIN(int iType, char* pCardInfo, char* pOutInfo);
long WINAPI iUnblockPIN_HSM_Step1(int iType, char* pCardInfo, char* pOutInfo);
long WINAPI iUnblockPIN_HSM_Step2(char* pKey, char* pOutInfo);
long WINAPI iUnblockPIN_HSM_Step3(char* pKey, char* pOutInfo);

/********************消费交易********************/
long WINAPI iDoDebit(int iType, char* pCardInfo, char* pPayInfo, char* pOutInfo);
long WINAPI iDoDebit_HSM_Step1(int iType, char* pCardInfo, char* pPayInfo, char* pOutInfo);
long WINAPI iDoDebit_HSM_Step2 (char* pKey, char* pOutInfo);

/********************读消费交易记录********************/
long WINAPI iReadDebitRecord(int iType, char* pOutInfo);


/**
**  Function:        读取证件信息。
**  Parameter[out]:  pOutInfo:  证件信息列表。具体说明详见Note。
**  Return:          操作成功返回0；否则返回小于0的错误码。
**  Note:
1、外国人居留证,返回数据：
I|英文名|中文姓名|性别|国籍|出生日期|永久居留证号码|证件签发日期|证件终止日期|当次申请受理机关代码|证件版本号|照片 BASE64|
2、港澳台居住证,返回数据：
J|姓名|性别|出生日期|地址|身份证号|签发机关|发卡日期|有效日期|通行证号码|签发次数|照片 BASE64|
3、居民身份证,返回数据：
|姓名|性别|民族|出生日期|地址|身份证号|发卡日期|有效日期|签发机关|照片BASE64|

**/

long WINAPI iReadIdentityCard(char* pOutInfo);



/*********************广州医保系统接口************************/

//读取社保卡中人员基础信息
long WINAPI iReadICCardGZ(char *aac003, char *aac002, char *bka100, char *errmsg);

//读取身份证中人员基础信息
long WINAPI iReadIDCardGZ(char *aac003, char *aac002, char *errmsg);

/*读取医保卡中人员基础信息
输出参数：aac003 姓名
          aac002 身份证号
          pka100 医保卡卡号*/
long WINAPI iReadMedicalCardGZ( char *aac003, char *aac002, char *pka100, char *errmsg);



#ifdef __cplusplus
}
#endif

#endif
