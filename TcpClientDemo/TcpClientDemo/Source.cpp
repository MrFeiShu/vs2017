#include<WINSOCK2.H>  
#include<STDIO.H>  
#include<iostream>  
#include<cstring>  
#include <string>
#include<WS2tcpip.h>
using namespace std;
#pragma comment(lib, "ws2_32.lib")  
int main()
{
	//��ʼ��WSA windows�Դ���socket
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}

	//�����ͻ����׽���
	while (true)
	{
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //�ͻ����׽���
		if (sclient == INVALID_SOCKET)
		{
			printf("invalid socket!");
			return 0;
		}

		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;
		serAddr.sin_port = htons(8888);
		inet_pton(AF_INET, "127.0.0.1", (void*)&serAddr.sin_addr.S_un.S_addr);
		if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) //��ָ��IP��ַ�Ͷ˿ڵķ��������
		{
			printf("connect error !");
			closesocket(sclient);
			return 0;
		}

		//string data;
		//cin >> data;
		//const char * sendData;
		//sendData = data.c_str(); //stringתconst char*
	 //   char * sendData1 = "��ã�TCP����ˣ����ǿͻ���\n";  
		//send(sclient, sendData1, strlen(sendData1), 0);

		printf("�������봫���Ӣ�ģ� \n");
		string data;
		cin >> data;
		const char * sendData2;
		sendData2 = data.c_str(); //stringתconst char*
		send(sclient, sendData2, strlen(sendData2), 0);


		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if (ret > 0) {
			recData[ret] = 0x00;
			printf(recData);
		}
		closesocket(sclient);

	}
	WSACleanup();
	return 0;

}