#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACKSIZE 5
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define OPSETSIZE 7

struct SqStack{
	char *base;
	char *top;
	int stacksize;
};//×Ö·ûÕ»

int InitStack(SqStack &S){
	S.base=(char *)malloc(STACKSIZE*sizeof(char));
	if(!S.base) exit(1);
	S.top=S.base;
	S.stacksize=STACKSIZE;
	return OK;
} //³õÊ¼»¯Õ»

char Push(SqStack &S,char e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(char*)realloc(S.base,
			(S.stacksize+STACKINCREMENT)*sizeof(char));
		if(!S.base) return ERROR;
		else 
		{
			S.top=S.base+S.stacksize;
			S.stacksize+=STACKINCREMENT;
		}
	}
	*S.top++=e;
	return e;
}

char Pop(SqStack &S,char &e)
{
	if(S.top==S.base) return ERROR;
	else e = * (--S.top);
	return e;
}

char GetTop(SqStack &S,char &e)
{
	if(S.top==S.base) return ERROR;
	else e=*(S.top-1);
	return e;
}

int StackEmpty(SqStack &S)
{
	if(S.top==S.base) return OK;
	else return ERROR;
	
	return OK;
}

