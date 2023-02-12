#include "mysocket.h"
#define TIMEOUT 2
const char* HOST="192.168.167.42:801";
const char* URL="/eportal/portal/login";
int main(){
    struct sockaddr_in server_addr;
    char request[512];
    char buf[BUFSIZ];
    memset(buf,0,sizeof(buf));
    GetHttpRequest(request,sizeof(request),URL,HOST);
    int fd=Socket(AF_INET,SOCK_STREAM,0);
    Connect(fd,&server_addr,sizeof(server_addr));
    SetSendTimeOut(fd,TIMEOUT);
    SetReceiveTimeOut(fd,TIMEOUT);
    printf("Sending Request...\n");
    printf("%s",request);
    Send(fd,request,strlen(request),0);
    printf("Sending Successful!...\n");
    printf("Receiving Response...\n");
    Recv(fd,buf,sizeof(buf),0);
    printf("Receiving Successful!...\n");
    Close(fd);
    printf("%s",buf);
    return 0;
}