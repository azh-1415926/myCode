#include "mysocket.h"
#include<fcntl.h>
#define SERVER_PORT 801
const char* SERVER_IP="192.168.167.42";
int GetHttpRequest(char *request,int size,const char *url,const char *host){
    const char* user_account="?user_account=%2C0%2C";
    const char* user_password="&user_password=";
    int fd;
    char myaccount[11];
    char mypassword[20];
    memset(request, 0, size);
    memset(myaccount,0,sizeof(myaccount));
    memset(mypassword,0,sizeof(mypassword));
    if((fd=open("passwd.txt",O_RDONLY))!=-1){
        int ret=read(fd,myaccount,10);
        if(ret<10){
            perror("account error!");
            close(fd);
            exit(-1);
        }
        read(fd,mypassword,sizeof(mypassword));
        close(fd);
        goto getRequest;
    }
    fd=open("passwd.txt",O_RDWR|O_CREAT,777);
    printf("please input account(10):");
    scanf("%10c",myaccount);
    printf("please input password(-)");
    scanf("%s",mypassword);
    write(fd,myaccount,10);
    write(fd,mypassword,strlen(mypassword));
    close(fd);
getRequest:
    strcat(request, "GET ");
    strcat(request, url);
    strcat(request, user_account);
    strcat(request, myaccount);
    strcat(request, user_password);
    strcat(request, mypassword);
    strcat(request, " HTTP/1.1\n");
    strcat(request, "Host: ");
    strcat(request, host);
    strcat(request, "\n");
    strcat(request, "\r\n");
    return 1;
}
int Socket(int domain,int type,int protocol){
    int fd=socket(domain,type,protocol);
    if(fd==-1){
        perror("socket error!");
        exit(-1);
    }
    return fd;
}
int Connect(int fd,struct sockaddr_in *server_addr,socklen_t server_len_t){
    memset(server_addr,0,server_len_t);
    server_addr->sin_family=AF_INET;
    server_addr->sin_port=htons(SERVER_PORT);
    inet_pton(AF_INET,SERVER_IP,&server_addr->sin_addr.s_addr);
    int ret=connect(fd,(struct sockaddr*)server_addr,server_len_t);
    if(ret==-1){
        perror("connect error!");
        exit(-1);
    }
    return fd;
}
int SetSendTimeOut(int fd,int time){
    struct timeval timeout={time,0};
    int ret=setsockopt(fd,SOL_SOCKET,SO_SNDTIMEO,(char*)&timeout,sizeof(struct timeval));
    if(ret==-1){
        perror("SetSendTimeOut failed,setsockopt error!");
        close(fd);
        exit(-1);
    }
    return 1;
}
int SetReceiveTimeOut(int fd,int time){
    struct timeval timeout={time,0};
    int ret=setsockopt(fd,SOL_SOCKET,SO_RCVTIMEO,(char*)&timeout,sizeof(struct timeval));
    if(ret==-1){
        perror("SetSendTimeOut failed,setsockopt error!");
        close(fd);
        exit(-1);
    }
    return 1;
}   
int Send(int fd,const char *request,int size,int flag){
    int ret=send(fd,request,size,flag);
    if(ret==-1){
        perror("send error!");
        close(fd);
        exit(-1);
    }
    return 1;
}
int Recv(int fd,char *buf,int size,int flag){
    int len=recv(fd,buf,size,flag);
    if(len==-1){
        perror("recv error!");
        close(fd);
        exit(-1);
    }
    return len;
}
int Close(int fd){
    int ret=close(fd);
    if(ret==-1){
        perror("close error!");
        exit(-1);
    }
    return 1;
}