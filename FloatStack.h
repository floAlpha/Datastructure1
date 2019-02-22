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
};//����ջ��������������

int FloatInitStack(FloatStack &S){
S.base=(float *)malloc(STACKSIZE*sizeof(float));
if(!S.base) exit(1);
S.top=S.base;
S.stacksize=STACKSIZE;
return OK;
} //��ʼ��ջ

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
{ // ��������ȼ���   
       
    '>','>','<','<','<','>','>',
    '>','>','<','<','<','>','>',
    '>','>','>','>','<','>','>', 
    '>','>','>','>','<','>','>',  
    '<','<','<','<','<','=',' ',  
    '>','>','>','>',' ','>','>',  
    '<','<','<','<','<',' ','=',   
  
};  
//���ʽ��ֵ
char OPSET[OPSETSIZE]={'+','-','*','/','(',')','#'};  //��������� 

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


float Operate(float a,unsigned char theta, float b)      //���㺯��Operate  
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
	SqStack OPTR;//����ջ
	FloatStack OPND;//������ջ
	InitStack(OPTR);
	Push(OPTR,'#');
	FloatInitStack(OPND);
	printf("���������������ʽ,��#�Ž�����\n");
	fflush(stdin);
    c =getchar();
	while (c!='#'||GetTop(OPTR,b)!='#')
	{   
		if(!In(c,OPSET)){//�������������������ջ
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
			switch (Precede(GetTop(OPTR,a),c))//����������ж��������ջ������������ȼ�
			{									
              case '<':
				  Push(OPTR,c);
				  c=getchar();
				  break;
			  case '=':						//���ȼ���ͬ�����ų�ջ
				  Pop(OPTR,x);
				  c=getchar();
				  break;
			  case '>':						//�������ȼ�����ǰ�ߣ�ִ�м��㣬��������ջ
				  Pop(OPTR,theta);
				  FloatPop(OPND,m);
				  FloatPop(OPND,n);
				  FloatPush(OPND,Operate(m,theta,n));
				  break;
			}
		}
	}
     printf("������Ϊ��  %f  \n",FloatGetTop(OPND,temp));
}


