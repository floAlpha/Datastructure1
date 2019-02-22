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
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
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
// �ڶ�β����Ԫ��
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
	if(!p){ exit(0);}
    p->data=e;p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return 1;
}

char DeQueue(LinkQueue &Q,char &e){
// ɾ������ǰ���Ԫ�أ�ͷָ�����
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