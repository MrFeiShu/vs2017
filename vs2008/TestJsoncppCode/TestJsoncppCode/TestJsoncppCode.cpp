// TestJsoncppCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TestJsoncppCode.h"

#include "include/json/json.h"
#include <fstream>
#include <string>

#pragma comment(lib."json_vc71_libmtd.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;


CString GetWorkDir() 
{  
	char pFileName[MAX_PATH]; 
	int nPos = GetCurrentDirectory( MAX_PATH, pFileName); 

	CString csFullPath(pFileName);  
	if( nPos < 0 ) 
		return CString(""); 
	else 
		return csFullPath; 
}

void WriteJsonData(const char* filename)
{
	Json::Reader reader;  
	Json::Value root; // Json::Value��һ�ֺ���Ҫ�����ͣ����Դ����������͡���int, string, object, array...        

	std::ifstream is;  
	is.open (filename, std::ios::binary );    
	if (reader.parse(is, root))  
	{  
		Json::Value arrayObj;   // ��������  
		Json::Value new_item, new_item1;  
		new_item["date"] = "2011-11-11";  
		new_item1["time"] = "11:11:11";  
		arrayObj.append(new_item);  // ���������Ա  
		arrayObj.append(new_item1); // ���������Ա  
		int file_size = root["files"].size();  
		for(int i = 0; i < file_size; ++i)  
			root["files"][i]["exifs"] = arrayObj;   // ����ԭjson�� 
		std::string out = root.toStyledString();  
		// ����޸�ʽjson�ַ���  
		Json::FastWriter writer;  
		std::string strWrite = writer.write(root);
		std::ofstream ofs;
		ofs.open("test_write.json");
		ofs << strWrite;
		ofs.close();
	}  

	is.close();  
}

int ReadJsonFromFile(const char* filename)  
{  
	Json::Reader reader;// ����json��Json::Reader   
	Json::Value root; // Json::Value��һ�ֺ���Ҫ�����ͣ����Դ����������͡���int, string, object, array...         

	std::ifstream is;  
	is.open (filename, std::ios::binary );    
	if (reader.parse(is, root, FALSE))  
	{  
		std::string code;  
		if (!root["files"].isNull())  // ���ʽڵ㣬Access an object value by name, create a null member if it does not exist.  
			code = root["uploadid"].asString();  
		
		code = root.get("uploadid", "null").asString();// ���ʽڵ㣬Return the member named key if it exist, defaultValue otherwise.    

		int file_size = root["files"].size();  // �õ�"files"���������  
		for(int i = 0; i < file_size; ++i)  // ��������  
		{  
			Json::Value val_image = root["files"][i]["images"];  
			int image_size = val_image.size();  
			for(int j = 0; j < image_size; ++j)  
			{  
				std::string type = val_image[j]["type"].asString();  
				std::string url  = val_image[j]["url"].asString(); 
				printf("type : %s, url : %s \n", type.c_str(), url.c_str());
			}  
		}  
	}  
	is.close();  

	return 0;  
}  

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: MFC initialization failed\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
	}

	//1.���ַ�������json
	const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";  

	Json::Reader reader;  
	Json::Value root;  
	if (reader.parse(str, root))    // reader��Json�ַ���������root��root������Json��������Ԫ��  
	{  
		printf("--------------���ַ�����ȡJSON---------------\n");
		std::string upload_id = root["uploadid"].asString();  // ���ʽڵ㣬upload_id = "UP000000"  
		int code = root["code"].asInt();                      // ���ʽڵ㣬code = 100 

		printf("upload_id : %s\ncode : %d \n", upload_id.c_str(), code);
	}  

	//2.���ļ�����json
	CString sTempPath = GetWorkDir() + "\\test_json.json";
	if (!CFileFind().FindFile(sTempPath))
	{
		printf("Not Find JSON File : %s", sTempPath);
	}
	else
	{
		printf("--------------���ļ���ȡJSON---------------\n");
		ReadJsonFromFile(sTempPath);
	}

	//3.���ļ�д��json
	WriteJsonData(sTempPath);

	system("pause");

	return nRetCode;
}