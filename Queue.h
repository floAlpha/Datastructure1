#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
//#include<iostream>
//using namespace std;

typedef struct QNode{
   char data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct  {
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

int InitQueue(LinkQueue &Q){
Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
if(!Q.front) exit(0);
Q.front->next=NULL;
return 1;
}

int QueueEmpty(LinkQueue &Q){
if(Q.front==Q.rear)
  return 1;
else return 0;
}

int EnQueue(LinkQueue &Q,char e){
// 在队尾插入元素
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
	if(!p){ exit(0);}
    p->data=e;p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return 1;
}

char DeQueue(LinkQueue &Q,char &e){
// 删除队列前面的元素，头指针后移
    QueuePtr p;
	if(Q.rear==Q.front) return 0;
	p=Q.front->next;
	e=p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
	{Q.rear=Q.front;
	}
	free(p);
	return 1;
}