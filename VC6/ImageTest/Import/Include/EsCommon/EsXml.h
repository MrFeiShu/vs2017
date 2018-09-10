//////////////////////////////////////////////////////////////////////////
// Copyright (c) 2013,�������Ķ������ݰ�ȫ���޹�˾
// All rights reserved.
// 
// �ļ����ƣ�
//		EsXml.h
//
// �ļ���ʶ��
//
// ժ   Ҫ��
//		XML�ļ������ӿڡ����ӿ�ֻ�ṩ�����صĽ������������ṩ����ת������չ���ȸ߼����ܡ�
//		���屾�ӿڵ��������ڣ���XML�������ܽ�����һ����󣬴Ӷ�ʹ��ʹ����������ı���ӿڵľ���ʵ�ַ�ʽ��
//		����ʵ�ַ�ʽ���������·�ʽ��ʹ�õ������⣬ʹ��ƽ̨SDK����������ȡ�
//		���ǵ�ѡ����ʹ�õ�������Դ�⡣
//		ע�⣺
//		1�����ӿ����ṩ�ĺ����������ַ��������ת��������
//		2�����ӿڵ�ĳЩ��������������Ƕ����ַ���ָ�룬�������߲���Ҫ����ָ����ڴ�����ͷŲ�����
//		�����ڡ�EsXmlFree��������֮��������ص��ڴ涼�������ͷš�
// 
// ��ǰ�汾��
//		1.0
//
// ��   �ߣ�
//		������
//
// ������ڣ�
//		2013��06��28��
//////////////////////////////////////////////////////////////////////////

#ifndef _ES_XML_H
#define _ES_XML_H

#ifdef __cplusplus
extern "C"
{
#endif
	typedef struct BlkXmlAttributeTag
	{
		const char* m_pszName;
		const char* m_pszValue;
	}BlkXmlAttribute;
	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		���ļ��м���XML��
	//
	//	����������
	//		[in]pszXmlDoc:			XML�ļ�·����
	//		[out]phXmlNode:			XML����ľ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.06.28
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsXmlLoadFromFile(IN const char* pszXmlDoc, OUT ESHANDLE* phXmlNode);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		���ڴ��м���XML��
	//
	//	����������
	//		[in]pu1Data:				�ڴ����ݡ�
	//		[out]u4Len:					���ݳ���
	//		[out]phXmlNode:				XML����ľ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.06.28
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsXmlLoadFromMemory(IN const u1* pu1Data, IN u4 u4Len, OUT ESHANDLE* phXmlNode);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		���XML������ַ������롣
	//
	//	����������
	//		[in]hXmlNode:				XML����ľ����
	//		[out]penCharSet:			ָ�룬ָ�������ַ�������Ӧ��Ӧ�ı��룩
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.06.28
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsXmlGetEncoding(IN ESHANDLE hXmlNode, EnCharSet* penCharSet);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		������Դ���ڵ��á�EsXmlLoadFromFile������EsXmlLoadFromMemory���ɹ�֮�����XML�����Ѿ�������ʹ�ã�
	//		������ô˽ӿ��ͷ���Ӧ���ڴ档
	//
	//	����������
	//		[in]hXmlNode:					XML����ľ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.06.28
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsXmlFree(const ESHANDLE hXmlNode);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		���ָ�����Ƶ��ӽڵ㣬���ж��ͬ���ڵ㣬�����ص�һ���ڵ㡣
	//
	//	����������
	//		[in]hXmlNode:					XML����ľ��
	//		[out]pszChildName:				�ӽڵ������
	//		[out]phXmlChildNode:			�ӽڵ�ľ��ָ�룬ָ���ȡ�����ӽڵ�ľ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.06.28
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsXmlGetSingleChild(IN ESHANDLE hXmlNode, IN const char* pszChildName, OUT ESHANDLE* phXmlChildNode);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		����ӽڵ��б���
	//
	//	����������
	//		[in]hXmlNode:					XML����ľ��
	//		[out]pphXmlNodeChildrenList:	�ӽڵ���б�������ָ��
	//		[in|out]pu4ChildrenNum:			�ӽڵ����Ŀ
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.06.28
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsXmlGetChildren(IN ESHANDLE hXmlNode, OUT ESHANDLE* phXmlNodeChildrenList, IN OUT u4* pu4ChildrenNum);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		��ýڵ�����ơ�
	//
	//	����������
	//		[in]hXmlNode:				XML����ľ��
	//		[out]ppszName:				�ڵ�����ƣ�����ָ�룬�����������ͷŶ�Ӧ�ڴ棬�����ڵ���ExXmlFree֮�󣬲�����ʹ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.06.28
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsXmlGetClassName(IN ESHANDLE hXmlNode, OUT const char** ppszName);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		��ýڵ���ı���������������һ���ڵ㣺��<nodeName>Node Text</nodeName>����
	//		��Դ˽ڵ���á�EsXmlGetText����*ppszNameָ����ڴ�Ϊ�ַ�����Node Text����
	//
	//	����������
	//		[in]hXmlNode:				XML����ľ��
	//		[out]ppszText:				�ڵ���ı���Ϣ������ָ�룬�����������ͷŶ�Ӧ�ڴ棬�����ڵ���ExXmlFree֮�󣬲�����ʹ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.06.28
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsXmlGetText(IN ESHANDLE hXmlNode, OUT const char** ppszName);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		��������б���
	//
	//	����������
	//		[in]hXmlNode:					XML����ľ��
	//		[out]pblkAttrList:				�����б��������ͷ���Ӧ�ڴ棬�����ڵ���ExXmlFree֮�󣬲�����ʹ��
	//		[in|out]pu4AttrCount:			���Ե���Ŀ��������ʱ��ָʾ�������Ĵ�С������Ӧ�Ľṹ��ƣ��������ʱ����ʾ���Ե�ʵ����Ŀ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.06.28
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsXmlGetAttributes(IN ESHANDLE hXmlNode, OUT BlkXmlAttribute* pblkAttrList, IN OUT u4* pu4AttrCount);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		�������ֵ��
	//
	//	����������
	//		[in]hXmlNode:				XML����ľ��
	//		[in]pszName:				���Ե�����
	//		[out]ppszValue:				���Ե�ֵ������ָ�룬�����ͷ���Ӧ���ڴ棬�����ڵ���ExXmlFree֮�󣬲�����ʹ��
	//
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.06.28
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsXmlGetAttribute(IN ESHANDLE hXmlNode,IN const char* pszName, OUT const char** ppszValue);


    //////////////////////////////////////////////////////////////////////////
    //	����˵��:  
    //		����xml����ʱ�Ƿ�ѹ���ո�Ӧ�ü���xmlǰ����
    //
    //	����������
    //		[in]bCondense:				����xmlʱ�Ƿ�ѹ���ո�
    //
    //
    // ����ֵ:
    //		�������붨��
    //
    // ����:
    //		��ӳ��
    // ����:    
    //		2014.09.13
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE EsXmlSetCondenseWhiteSpace(ESBOOL bCondense);

    //////////////////////////////////////////////////////////////////////////
    //	����˵��:  
    //		��ȡxml����ʱ�Ƿ�ѹ���ո�
    //
    //	����������
    //		[out]pbCondense:				����xmlʱ�Ƿ�ѹ���ո�
    //
    //
    // ����ֵ:
    //		�������붨��
    //
    // ����:
    //		��ӳ��
    // ����:    
    //		2014.09.13
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE EsXmlGetCondenseWhiteSpace(ESBOOL* pbCondense);


    //////////////////////////////////////////////////////////////////////////
    //	����˵��:  
    //		����xml�ĵ��ṹ
    //
    //	����������
    //      [in]enCharSet          �ĵ�����
    //		[out]phXml:				xml�ĵ����
    //
    //
    // ����ֵ:
    //		�������붨��
    //
    // ����:
    //		��ӳ��
    // ����:    
    //		2015.04.24
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE EsXmlCreate(EnCharSet enCharSet, ESHANDLE* phXml);

    //////////////////////////////////////////////////////////////////////////
    //	����˵��:  
    //		����һ���ӽڵ�
    //
    //	����������
    //      [in]pszClassName            �ڵ�tag
    //      [in]pszValue                �ڵ�value
    //		[out]phChild:				�����ӽڵ�ľ��
    //
    //
    // ����ֵ:
    //		�������붨��
    //
    // ����:
    //		��ӳ��
    // ����:    
    //		2015.04.24
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE EsXmlAddChild(ESHANDLE hXml, const char* pszClassName, const char* pszValue, ESHANDLE* phChild);

    //////////////////////////////////////////////////////////////////////////
    //	����˵��:  
    //		���½ڵ��ֵ
    //
    //	����������
    //      [in]pszText �ڵ�ֵ
    //
    //
    // ����ֵ:
    //		�������붨��
    //
    // ����:
    //		��ӳ��
    // ����:    
    //		2015.04.24
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE EsXmlSetText(ESHANDLE hXml, const char* pszText);

    //////////////////////////////////////////////////////////////////////////
    //	����˵��:  
    //		��������ֵ���������Ѵ��ڣ���������ֵ��������������
    //
    //	����������
    //      [in]pszAttrName ��������
    //      [in]pszAttrValue ����ֵ
    //
    //
    // ����ֵ:
    //		�������붨��
    //
    // ����:
    //		��ӳ��
    // ����:    
    //		2015.04.24
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE EsXmlSetAttribute(ESHANDLE hXml, const char* pszAttrName, const char* pszAttrValue);


    //////////////////////////////////////////////////////////////////////////
    //	����˵��:  
    //		��xml�ĵ����浽�ļ�
    //
    //	����������
    //      [in]pszPath �ļ�·��
    //
    //
    // ����ֵ:
    //		�������붨��
    //
    // ����:
    //		��ӳ��
    // ����:    
    //		2015.04.24
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE EsXmlWriteToFile(ESHANDLE hXml, const char* pszPath);




#ifdef __cplusplus
}
#endif


#endif