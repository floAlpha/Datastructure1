#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;


LinkList CreateList_L(int n){
  LinkList L;
  LinkList p;
  LinkList Last;
  L=(LinkList)malloc(sizeof(LNode));
  L->next=NULL;
  Last = L;
 
  for (int i=0;i<n;i++)
  {
   p=(LinkList)malloc(sizeof(LNode));
   scanf(" %d",&p->data); 
   p->next = NULL;
   Last->next = p;
   Last = p;
  //p->next = L->next;
  }
   printf("输入的元素:\n");
return L;
}/*创建函数*/



int InsertList_L(LinkList &L,int i,int e){
int j;
LinkList p,s;
p=L;j=0;
while(p&&j<i-1){p=p->next;j++;}
if(!p||j>i-1) return ERROR;
s = (LinkList)malloc(sizeof(LNode));
s -> data = e; s -> next = p -> next; p -> next = s; 
return OK;
}/*插入函数*/




int DeleteList_L(LinkList &L,int i){
int e;
LinkList p,q;
p = L;
int j = 0;
while (p -> next && j < i-1){
p = p->next;
++j;
}

if (!(p -> next) || j > i-1 )
return ERROR;
q = p ->next ;
p -> next = q -> next;
e = q -> data;

free(q);
return e;
}/*删除函数*/



int GetElem_L(LinkList &L,int i){

LinkList p;
p=L;
int j = 0;
while (p -> next && j<i)
{
p = p->next;
++j;
}

int e;
e = p -> data;
return e;
} /*查找函数*/


int ListLength_L(LinkList &L){

    LinkList p;
	p = L;                        
	int count = 0;
	while (p->next){
	count++;
	p = p->next;
	}
 return count;
}

int Locate_L(LinkList &L,int e){
LinkList p;
p = L;
int i=0;
int j=0;

for (;j<=ListLength_L(L);j++){
if (p ->data ==e){
//cout<<j<<"  ";
return j;
i=1;
}
p = p->next;
}
if (i==0)
printf("Do not find %d",e);
return 0;
}//定位函数

void Show_L(LinkList &L){
LinkList p;
p=L->next;
while(p){
printf("%d  ",p->data);
p=p->next;
}
printf("\n");
}/*显示函数*/
