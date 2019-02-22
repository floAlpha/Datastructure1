#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACKSIZE 5
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define OPSETSIZE 7

struct FloatStack{
float *base;
float *top;
int stacksize;
};//浮点栈，用于四则运算

int FloatInitStack(FloatStack &S){
S.base=(float *)malloc(STACKSIZE*sizeof(float));
if(!S.base) exit(1);
S.top=S.base;
S.stacksize=STACKSIZE;
return OK;
} //初始化栈

float FloatPush(FloatStack &S,float e)
{
if(S.top-S.base>=S.stacksize)
{
	S.base=(float*)realloc(S.base,
		(S.stacksize+STACKINCREMENT)*sizeof(float));
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

float FloatPop(FloatStack &S,float &e)
{
	if(S.top==S.base) return ERROR;
	else e = * (--S.top);
	return e;
}

float FloatGetTop(FloatStack &S,float &e)
{
	if(S.top==S.base) return ERROR;
	else e=*(S.top-1);
	return e;
}

int FloatStackEmpty(FloatStack &S)
{
	if(S.top==S.base) return OK;
	else return ERROR;

return OK;
}
 
unsigned char Prior[7][7] =  
{ // 运算符优先级表   
       
    '>','>','<','<','<','>','>',
    '>','>','<','<','<','>','>',
    '>','>','>','>','<','>','>', 
    '>','>','>','>','<','>','>',  
    '<','<','<','<','<','=',' ',  
    '>','>','>','>',' ','>','>',  
    '<','<','<','<','<',' ','=',   
  
};  
//表达式求值
char OPSET[OPSETSIZE]={'+','-','*','/','(',')','#'};  //计算符数组 

bool In(char Test,char *TestOp)  
{  
    bool find =false;
    for (int i=0; i< OPSETSIZE; i++)  
    {  
        if(Test == TestOp[i])  
            find =true;   
    }   
		return find;
}   


float Operate(float a,unsigned char theta, float b)      //计算函数Operate  
{  
    switch(theta)  
    {  
    case '+': return b+a;   
    case '-': return b-a;   
    case '*': return b*a;   
    case '/': return b/a;   
    default : return 0;   
    }   
}   

int ReturnOpOrd(char op,char *TestOp)  
{   
    for(int i=0; i< OPSETSIZE; i++)  
    {  
        if (op == TestOp[i])  
            return i;  
    }  
	return 0;
}  

char Precede(char Aop, char Bop)  
{   
    return Prior[ReturnOpOrd(Aop,OPSET)][ReturnOpOrd(Bop,OPSET)];   
}  


void Caculate(){
	float temp=0;
	int flag=0;
	float m,n;
	char x,a,b,c;
	char theta;
	SqStack OPTR;//符号栈
	FloatStack OPND;//操作数栈
	InitStack(OPTR);
	Push(OPTR,'#');
	FloatInitStack(OPND);
	printf("输入简单四则运算表达式,以#号结束：\n");
	fflush(stdin);
    c =getchar();
	while (c!='#'||GetTop(OPTR,b)!='#')
	{   
		if(!In(c,OPSET)){//不是运算符，进操作数栈
			if(flag){
				FloatPop(OPND,temp);	
				FloatPush(OPND,c-(float)'0'+10*temp);}
			else{
				FloatPush(OPND,c-(float)'0');
			}	
			flag++;
		    c = getchar();
		}
		else{
			flag = 0;
			switch (Precede(GetTop(OPTR,a),c))//是运算符，判断与运算符栈定运算符的优先级
			{									
              case '<':
				  Push(OPTR,c);
				  c=getchar();
				  break;
			  case '=':						//优先级相同，符号出栈
				  Pop(OPTR,x);
				  c=getchar();
				  break;
			  case '>':						//后者优先级大于前者，执行计算，操作数出栈
				  Pop(OPTR,theta);
				  FloatPop(OPND,m);
				  FloatPop(OPND,n);
				  FloatPush(OPND,Operate(m,theta,n));
				  break;
			}
		}
	}
     printf("计算结果为：  %f  \n",FloatGetTop(OPND,temp));
}


