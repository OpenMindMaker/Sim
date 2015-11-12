
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <time.h>


#pragma comment (lib, "ws2_32.lib")
#define BUF_SIZE 30
void ErrorHandling(char *message);

int main(int argc, char *argv[])
{
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	boolean registration = false;
	char buf[BUF_SIZE] = {0};
	char msg[BUF_SIZE] = {0};
	int readCnt;

	SOCKADDR_IN servAdr, clntAdr;
	int clntAdrSz;

	if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0)
		ErrorHandling("WSAStartup() error!"); 


	hServSock=socket(PF_INET, SOCK_STREAM, 0);		

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family=AF_INET;
	servAdr.sin_addr.s_addr=htonl(INADDR_ANY);
	servAdr.sin_port=htons(7773);

	bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr));
	listen(hServSock, 5);

	
	

	

	while(1){ 
		//time_t curr;
		//struct tm *d;
		//d=localtime(&curr);
		//curr=time(NULL);
		//	
		//printf("%d년%d월%d일\n", d->tm_year+1900, d->tm_mon+1, d->tm_mday);
		//printf("현재시간\n");
		//printf("%d시%d분%d초\n", d->tm_hour, d->tm_min, d->tm_sec);

		clntAdrSz=sizeof(clntAdr);    
		hClntSock=accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSz);
		puts("connected.....");
		recv(hClntSock,msg,BUF_SIZE, 0);
		puts(msg);	
		if(!strcmp("\n",msg)){
			if(registration){
				send(hClntSock,"TRUE\n",BUF_SIZE,0);
			}
			else{
				send(hClntSock,"FALSE\n",BUF_SIZE,0);
			}
		}
		if(! strcmp("send\n",msg)){
			FILE * writefile =fopen("FromClient.wav", "wb");
			int i = 0;
			while((readCnt=recv(hClntSock,(char*)&buf, BUF_SIZE, 0))!=0)
			{

				size_t r=fwrite((void*)buf, 1, readCnt, writefile);
			}
			puts("Received file data");
			shutdown(hClntSock, 2);
			fclose(writefile);

		}
		if(! strcmp("receive\n",msg)){
			registration = true;
			FILE * readfile =fopen("FromClient.wav", "rb"); 
			while(1)
			{
				readCnt=fread((void*)buf, 1, BUF_SIZE, readfile);
				int sentData=0;
				while(1){
					int r=send(hClntSock, (char*)&buf+sentData, readCnt-sentData, 0);
					if(r==SOCKET_ERROR){
						if(GetLastError()==WSAEWOULDBLOCK){
							Sleep(10);
							continue;
						}
						else{
							puts("file err");
							fclose(readfile);
							break;
						}
					}
					sentData+=r;
					if(sentData==readCnt)
						break;

				}
				if(readCnt<BUF_SIZE)
					break;
			}
			shutdown(hClntSock, 1);
			puts("Sended file data");
			fclose(readfile);

			
		}

		closesocket(hClntSock);
	}
	closesocket(hServSock);
	WSACleanup();
	return 0;
}

void ErrorHandling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

