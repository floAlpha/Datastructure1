#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACKSIZE 5
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define OPSETSIZE 7

struct IntStack{
int *base;
int *top;
int stacksize;
};//整形栈，没有用到

int IntInitStack(IntStack &S){
S.base=(int *)malloc(STACKSIZE*sizeof(int));
if(!S.base) exit(1);
S.top=S.base;
S.stacksize=STACKSIZE;
return OK;
} //初始化栈

int IntPush(IntStack &S,int e)
{
if(S.top-S.base>=S.stacksize)
{
	S.base=(int*)realloc(S.base,
		(S.stacksize+STACKINCREMENT)*sizeof(int));
	if(!S.base) return ERROR;
	else 
	{
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
}
     *S.top++=e;
	 return OK;
}

int IntPop(IntStack &S,int &e)
{
	if(S.top==S.base) return ERROR;
	else e = * (--S.top);
	return OK;
}

float IntGetTop(IntStack &S,int &e)
{
	if(S.top==S.base) return ERROR;
	else e=*(S.top-1);
	return OK;
}

int IntStackEmpty(IntStack &S)
{
	if(S.top==S.base) return OK;
	else return ERROR;

return OK;
}
