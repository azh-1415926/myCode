#include "linkQueue.h"
#include<stdlib.h>
bool linkQueueInitalize(linkQueue* ppQueue){
    if(ppQueue==NULL){
        printf("please input incorrect point,Initalize failed!\n");
        return false;
    }
    *ppQueue=(linkQueueNode*)malloc(sizeof(struct linkQueueNode));
    if(*ppQueue==NULL){
        printf("malloc error,Initalize failed!\n");
        return false;
    }
    (*ppQueue)->next=NULL;
    return true;
}
bool linkQueueIsEmpty(linkQueue queue){
    if(queue==NULL){
        printf("queue is null,please initalize it!\n");
        return true;
    }
    return queue->next==NULL;
}
bool linkQueueEnqueue(linkQueue queue,Type data){
    if(queue==NULL){
        printf("queue is null,Enqueue failed!\n");
        return false;
    }
    linkQueue pQueue=queue->next;
    queue->next=(linkQueueNode*)malloc(sizeof(struct linkQueueNode));
    if(queue->next==NULL){
        printf("malloc error,Enqueue failed!\n");
        queue->next=pQueue;
        return false;
    }
    queue->next->next=pQueue;
    queue->next->data=data;
    return true;
}
Type linkQueueDequeue(linkQueue queue){
    if(queue==NULL){
        printf("queue is null,Dequeue failed!\n");
        return 0;
    }else if(queue->next==NULL){
        printf("queue is empty,Dequeue failed!\n");
        return 0;
    }
    Type e;
    linkQueue pQueue=queue->next;
    queue->next=pQueue->next;
    e=pQueue->data;
    free(pQueue);
    return e;
}
bool linkQueueFree(linkQueue queue){
    if(queue==NULL){
        printf("queue is null,Free failed!\n");
        return false;
    }
    linkQueue pQueue=NULL;
    while(queue){
        pQueue=queue;
        queue=queue->next;
        free(pQueue);
    }
    queue=NULL;
    return true;
}