#ifndef _BOGY_SETTINGS_H_
#define _BOGY_SETTINGS_H_

#define TEXT_IS_FIRST_CHANGE_ORG_PIN	TEXT("FirstChangeOrg")

BOOL MYbankGetDwordOptions(LPCTSTR pszOptName, DWORD dwDefVal, DWORD* pdwOptVal);
BOOL MYbankSetDwordOptions(LPCTSTR pszOptName, DWORD dwOptVal);

#endif
