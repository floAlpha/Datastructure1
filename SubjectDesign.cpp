#include <stdio.h>
#include "LinkList.h"
#include "Stack.h"
#include "BiTree.h"
#include "Graph.h"
#include "Array.h"
#include "IntStack.h"
#include "TopologicalSort.h"
#include "ShortestPath.h"
#include "FloatStack.h"


void ShowMainMenu(){
printf("\n");
printf("*******************�㷨�����ݽṹ******************\n");
printf("* 1  ������Ļ���������Ӧ��                       *\n");
printf("* 2  ջ�Ļ���������Ӧ��                           *\n");
printf("* 3  ��Ԫ��Ļ���������Ӧ��                       *\n");
printf("* 4  ���Ļ���������Ӧ��                           *\n");
printf("* 5  ͼ�Ļ���������Ӧ��                           *\n");
printf("* 6  �˳�                                         *\n");
printf("***************************************************\n");
}

void LinkList_Menu(){
    int n;
	LinkList L;
	int num;
do{
printf("\n");
printf("**************������Ļ���������Ӧ��***************\n");
printf("* 1  ����                                         *\n");
printf("* 2  ����                                         *\n");
printf("* 3  ɾ��                                         *\n");
printf("* 4  ����                                         *\n");
printf("* 5  ��ʾ                                         *\n");
printf("* 6  �˳�                                         *\n");
printf("***************************************************\n");
printf("��ѡ��");
fflush(stdin);
scanf(" %d",&n);
switch(n){
case 1:
	//������Ĵ���
	printf("����Ԫ�ظ���:\n");
	fflush(stdin);
	scanf("%d",&num);

	printf("����Ԫ��(int ��),�м��ÿո����:\n");
	L=CreateList_L(num);
	Show_L(L);
	break;
case 2:
	//������Ĳ���
	int i,e;
	printf("����������λ�ü�Ԫ�أ��ÿո����:\n");
	scanf(" %d %d",&i,&e);
	if(InsertList_L(L,i,e)){
		printf("�������µ�����:\n");
		Show_L(L);}
	else
		printf("��������");
	break;
case 3:
	//�������ɾ��
	printf("����ڵ�λ��ɾ��Ԫ��:\n");
	fflush(stdin);
	scanf(" %d",&i);
	DeleteList_L(L,i);
	printf("ɾ���ڵ���������:\n");
	Show_L(L);
	break;
case 4:
	//������Ĳ���
	printf("ͨ��λ�ò��ҽڵ�Ԫ��:\n");
	scanf(" %d",&i);
	printf("��%d��λ�õ�Ԫ���� %d\n",i,Loacate_L(L,i));
	break;
case 5:
	//���������ʾ
	printf("��ʾ����:\n");
	Show_L(L);
	break;
case 6: system("cls");break;
default:
	printf("ERROR!");break;		
}
}while(n!=6);
}

void Stack_Menu(){ 
    int n;
	SqStack S;
    InitStack(S);
    char e;
do{
printf("\n");
printf("****************ջ�Ļ���������Ӧ��*****************\n");
printf("* 1  ��ջ                                         *\n");
printf("* 2  ��ջ                                         *\n");
printf("* 3  ȡջ��Ԫ��                                   *\n");
printf("* 4  ���ʽ���                                   *\n");
printf("* 5  �˳�                                         *\n");
printf("***************************************************\n");
printf("��ѡ��");
fflush(stdin);
scanf("%d",&n);
switch(n){
case 1:
	//��ջ
	printf("��ջһ��char������:\n");
	scanf(" %c",&e);
	if(Push(S,e)){printf("��ջ�ɹ�\n");}
	break;
case 2:
	//��ջ
	if(Pop(S,e))
	   	printf(" %c ��ջ\n",e);
	else printf("�ַ�ջ���Ѿ�û��Ԫ��");
	break;
case 3:
	//ȡ��ջ��Ԫ��
	if(GetTop(S,e))
	printf("ջ��Ԫ���� :%c\n",e);
	else printf("�ַ�ջ���Ѿ�û��Ԫ��");
	break;
case 4:
	//���ʽ���
	Caculate();
	break;
case 5:system("cls");break;
default:
	printf("ERROR!");break;
}
}while(n!=5);
}


void Array_Menu(){ 
int n;
TSMatrix M;
TSMatrix N,Q;
do{
printf("\n");
printf("****************��Ԫ��Ļ���������Ӧ��*************\n");
printf("* 1  ����                                         *\n");
printf("* 2  �ӷ�                                         *\n");
printf("* 3  ����                                         *\n");
printf("* 4  �˷�                                         *\n");
printf("* 5  ��ʾ                                         *\n");
printf("* 6  �˳�                                         *\n");
printf("***************************************************\n");
printf("��ѡ��");
scanf(" %d",&n);
switch(n){
case 1://��Ԫ�鴴��
	printf("����ϵ��������Ԫ�� M:\n");
	if(CreateSMatrix(M)){
    output(M);
	PrintSMatrix(M);}
	else{	printf("����ʧ��!\n");	}

	printf("����ϵ��������Ԫ�� N:\n");
	if(CreateSMatrix(N)){
	PrintSMatrix(N);
    output(N);}
	else{	printf("����ʧ��!\n");	}

	break;
case 2://��Ԫ��ӷ�
	AddSMatrix(M,N,Q);
    printf("M + N =\n");
    PrintSMatrix(Q);
	break;
case 3://��Ԫ�����
	SubSMatrix(M,N,Q);
	printf("M - N =\n");
    PrintSMatrix(Q);
	break;
case 4://��Ԫ��˷�
	MultiSMatrix(M,N,Q);
	printf("M * N =\n");
    PrintSMatrix(Q);
	break;
case 5://��ʾ��Ԫ��  
    printf("M:\n");
	PrintSMatrix(M);
	printf("N:\n");
	PrintSMatrix(N);
	break;
case 6:system("cls");break;
default:
	printf("ERROR!");break;
}
}while(n!=6);
}

void BiTree_Menu(){ 
int n; 
int count=0; 
BiTree T;
do{
printf("\n");
printf("**************�������Ļ���������Ӧ��***************\n");
printf("* 1  ����������                                   *\n");
printf("* 2  ����������                                   *\n");
printf("* 3  ����������ȼ�Ҷ�ӽ�����                   *\n");
printf("* 4  ���Һ���                                     *\n");
printf("* 5  ����˫��                                     *\n");
printf("* 6  �����ֵ�                                     *\n");
printf("* 7  �˳�                                         *\n");
printf("***************************************************\n");
printf("��ѡ��");

scanf(" %d",&n);
switch(n){

case 1://����������

    printf("�������������:\n");
	fflush(stdin);
    CreateBiTree(T);
	break;
case 2://����������

	printf("�������: ");
    PreOrderTraverse(T,Print); 
    printf("\n");

    printf("�������: ");
    InOrderTraverse(T,Print);
    printf("\n");

    printf("�������: ");
    PostOrderTraverse(T,Print);
    printf("\n");
	
	break;
case 3://����ڵ��Ҷ�Ӹ���
	printf("Ҷ����: ");
    CountLeaf(T,count);
    printf("%d ",count);
    printf("\n");

    printf("���: ");
    printf("%d ",Depth(T));
    printf("\n");
	
	break;
case 4://���Һ���
    char e;
    printf("����һ��Ҷ�Ӳ����亢��:");
    scanf(" %c",&e);

    printf("%c��������:",e);
    if(LeftChild(T,e)){}
    else printf("ERROR"); 
    printf("\n");

    printf("%c���Һ�����:",e);
    if(RightChild(T,e)){}
    else printf("ERROR"); 
    printf("\n");
	break;
case 6://�����ֵ�
	printf("����һ��Ҷ�Ӳ��������ֵ�:");
    scanf(" %c",&e);

    printf("%c�����ֵ��� :",e);
    if(RightSiBling(T,e)){}
    else printf("ERROR"); 
    printf("\n");

    printf("����һ��Ҷ�Ӳ��������ֵ�:");
    scanf(" %c",&e);
    printf("%c�����ֵ��� :",e);
    if(LeftSiBling(T,e)){}
    else printf("ERROR"); 
    printf("\n");
	
	
	break;
case 5:
	printf("����һ��Ҷ�Ӳ���˫��:");
    scanf(" %c",&e);
    printf("%c��˫���� :",e);
    if(Parent(T,e)){}
    else printf("ERROR"); 
    printf("\n");
	break;
case 7:system("cls");break;
default:
	printf("ERROR!");break;
}
}while(n!=7);
}

void Graph_Menu(){ 
int n;
MGraph G;
do{
printf("\n");
printf("****************ͼ�Ļ���������Ӧ��******************\n");
printf("* 1  ��������ͼ                                    *\n");
printf("* 2  ����������                                    *\n");
printf("* 3  ��������ͼ                                    *\n");
printf("* 4  ����������                                    *\n");
printf("* 5  ͼ�ı���                                      *\n");
printf("* 6  ��С������                                    *\n");
printf("* 7  ��������                                      *\n");
printf("* 8  ���·��                                      *\n");
printf("* 9  �ؼ�·��                                      *\n");
printf("* 10 �˳�                                          *\n");
printf("****************************************************\n");
printf("��ѡ��");
fflush(stdin);
scanf(" %d",&n);
switch(n){
case 1://��������ͼ
	if(CreateUDG(G)){
	printMGraph(G);
	}
	break;
case 2://����������
	if(CreateUDN(G)){
	printMGraph(G);
	}break;
case 3://��������ͼ
    if(CreateDG(G)){
	printMGraph(G);
	}break;
case 4://����������
    if(CreateDN(G)){
	printMGraph(G);
	}break;
case 5://ͼ�ı���
    DFSTraverse(G);
    cout<<endl;
    BFSTraverse(G);
    cout<<endl;
	break;
case 6://��С������������
	//printf("����ڵ㿪ʼ������С������:\n");
	//char c;
	fflush(stdin);
	//scanf(" %c",&c);
	printf("��С������(�ӵ�һ���ڵ㿪ʼ):\n");
	MiniSpanTree_prim(G);
	break;
	
case 7://��������
	printf("����һ��AOV����������������:\n");
	ALGraph G;
    CreateAOV(G);
	TopicalSort(G);
	break;
case 8://���·��
    printf("���·��(���������㷨):\n");
	MGraph g,f;
	char from,to;
	f=CreateDN_F(g);
	printf("������·������������(�м䲻��Ҫ�ո�):\n");
	fflush(stdin);
	scanf("%c %c",&from,&to);
	ShortestPath(f,from,to);
	break;
case 9://�ؼ�·��
  
	ALGraph Ga;
	IntStack T;
	int ve[20];
	int vl[20];
	IntInitStack(T);
	printf("����һ���µ�AOE����ؼ�·����\n");
	CreateAOE(Ga);

	if(!TopologicalOrder(Ga,ve,T))
		printf("ͼ���л�������ʧ��!");
	else{
        printf("��ʼ	����	���翪ʼʱ��  ����ʼʱ��    ��ʱ	�Ƿ�Ϊ�ؼ��\n");
		CriticalPath(Ga,ve,vl,T);

	}
	break;
case 10:system("cls");break;
default:
	printf("ERROR!");break;
}
}while(n!=10);
}

void main(){
int n;
do{
ShowMainMenu();
printf("��ѡ��");
scanf(" %d",&n);
switch(n){
case 1:system("cls");LinkList_Menu();break;
case 2:system("cls");Stack_Menu();break;
case 3:system("cls");Array_Menu();break;
case 4:system("cls");BiTree_Menu();break;
case 5:system("cls");Graph_Menu();break;
case 6:break;
default:printf("ERROR!");break;
}
}while(n!=6);
}
