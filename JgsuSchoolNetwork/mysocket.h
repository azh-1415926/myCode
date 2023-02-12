#ifndef _MY_SOCKET_H_
#define _MY_SOCKET_H_
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int GetHttpRequest(char *request,int size,const char *url,const char *host);
int Socket(int domain,int type,int protocol);
int Connect(int fd,struct sockaddr_in *server_addr,socklen_t server_len_t);
int SetSendTimeOut(int fd,int time);
int SetReceiveTimeOut(int fd,int time);
int Send(int fd,const char *request,int size,int flag);
int Recv(int fd,char *buf,int size,int flag);
int Close(int fd);
#endif