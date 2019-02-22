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
printf("*******************算法与数据结构******************\n");
printf("* 1  单链表的基本操作及应用                       *\n");
printf("* 2  栈的基本操作及应用                           *\n");
printf("* 3  三元组的基本操作及应用                       *\n");
printf("* 4  树的基本操作及应用                           *\n");
printf("* 5  图的基本操作及应用                           *\n");
printf("* 6  退出                                         *\n");
printf("***************************************************\n");
}

void LinkList_Menu(){
    int n;
	LinkList L;
	int num;
do{
printf("\n");
printf("**************单链表的基本操作及应用***************\n");
printf("* 1  创建                                         *\n");
printf("* 2  插入                                         *\n");
printf("* 3  删除                                         *\n");
printf("* 4  查找                                         *\n");
printf("* 5  显示                                         *\n");
printf("* 6  退出                                         *\n");
printf("***************************************************\n");
printf("请选择：");
fflush(stdin);
scanf(" %d",&n);
switch(n){
case 1:
	//单链表的创建
	printf("链表元素个数:\n");
	fflush(stdin);
	scanf("%d",&num);

	printf("输入元素(int 型),中间用空格隔开:\n");
	L=CreateList_L(num);
	Show_L(L);
	break;
case 2:
	//单链表的插入
	int i,e;
	printf("输入所插入位置及元素，用空格隔开:\n");
	scanf(" %d %d",&i,&e);
	if(InsertList_L(L,i,e)){
		printf("插入后的新的链表:\n");
		Show_L(L);}
	else
		printf("错误输入");
	break;
case 3:
	//单链表的删除
	printf("输入节点位置删除元素:\n");
	fflush(stdin);
	scanf(" %d",&i);
	DeleteList_L(L,i);
	printf("删除节点后的新链表:\n");
	Show_L(L);
	break;
case 4:
	//单链表的查找
	printf("通过位置查找节点元素:\n");
	scanf(" %d",&i);
	printf("第%d个位置的元素是 %d\n",i,Loacate_L(L,i));
	break;
case 5:
	//单链表的显示
	printf("显示链表:\n");
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
printf("****************栈的基本操作及应用*****************\n");
printf("* 1  进栈                                         *\n");
printf("* 2  出栈                                         *\n");
printf("* 3  取栈顶元素                                   *\n");
printf("* 4  表达式求解                                   *\n");
printf("* 5  退出                                         *\n");
printf("***************************************************\n");
printf("请选择：");
fflush(stdin);
scanf("%d",&n);
switch(n){
case 1:
	//进栈
	printf("进栈一个char型数据:\n");
	scanf(" %c",&e);
	if(Push(S,e)){printf("进栈成功\n");}
	break;
case 2:
	//出栈
	if(Pop(S,e))
	   	printf(" %c 出栈\n",e);
	else printf("字符栈中已经没有元素");
	break;
case 3:
	//取出栈顶元素
	if(GetTop(S,e))
	printf("栈顶元素是 :%c\n",e);
	else printf("字符栈中已经没有元素");
	break;
case 4:
	//表达式求解
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
printf("****************三元组的基本操作及应用*************\n");
printf("* 1  创建                                         *\n");
printf("* 2  加法                                         *\n");
printf("* 3  减法                                         *\n");
printf("* 4  乘法                                         *\n");
printf("* 5  显示                                         *\n");
printf("* 6  退出                                         *\n");
printf("***************************************************\n");
printf("请选择：");
scanf(" %d",&n);
switch(n){
case 1://三元组创建
	printf("输入系数矩阵三元组 M:\n");
	if(CreateSMatrix(M)){
    output(M);
	PrintSMatrix(M);}
	else{	printf("创建失败!\n");	}

	printf("输入系数矩阵三元组 N:\n");
	if(CreateSMatrix(N)){
	PrintSMatrix(N);
    output(N);}
	else{	printf("创建失败!\n");	}

	break;
case 2://三元组加法
	AddSMatrix(M,N,Q);
    printf("M + N =\n");
    PrintSMatrix(Q);
	break;
case 3://三元组减法
	SubSMatrix(M,N,Q);
	printf("M - N =\n");
    PrintSMatrix(Q);
	break;
case 4://三元组乘法
	MultiSMatrix(M,N,Q);
	printf("M * N =\n");
    PrintSMatrix(Q);
	break;
case 5://显示三元组  
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
printf("**************二叉树的基本操作及应用***************\n");
printf("* 1  创建二叉树                                   *\n");
printf("* 2  遍历二叉树                                   *\n");
printf("* 3  计算树的深度及叶子结点个数                   *\n");
printf("* 4  查找孩子                                     *\n");
printf("* 5  查找双亲                                     *\n");
printf("* 6  查找兄弟                                     *\n");
printf("* 7  退出                                         *\n");
printf("***************************************************\n");
printf("请选择：");

scanf(" %d",&n);
switch(n){

case 1://创建二叉树

    printf("先序输入二叉树:\n");
	fflush(stdin);
    CreateBiTree(T);
	break;
case 2://遍历二叉树

	printf("先序遍历: ");
    PreOrderTraverse(T,Print); 
    printf("\n");

    printf("中序遍历: ");
    InOrderTraverse(T,Print);
    printf("\n");

    printf("后序遍历: ");
    PostOrderTraverse(T,Print);
    printf("\n");
	
	break;
case 3://计算节点和叶子个数
	printf("叶子数: ");
    CountLeaf(T,count);
    printf("%d ",count);
    printf("\n");

    printf("深度: ");
    printf("%d ",Depth(T));
    printf("\n");
	
	break;
case 4://查找孩子
    char e;
    printf("输入一个叶子查找其孩子:");
    scanf(" %c",&e);

    printf("%c的左孩子是:",e);
    if(LeftChild(T,e)){}
    else printf("ERROR"); 
    printf("\n");

    printf("%c的右孩子是:",e);
    if(RightChild(T,e)){}
    else printf("ERROR"); 
    printf("\n");
	break;
case 6://查找兄弟
	printf("输入一个叶子查找其右兄弟:");
    scanf(" %c",&e);

    printf("%c的右兄弟是 :",e);
    if(RightSiBling(T,e)){}
    else printf("ERROR"); 
    printf("\n");

    printf("输入一个叶子查找其左兄弟:");
    scanf(" %c",&e);
    printf("%c的左兄弟是 :",e);
    if(LeftSiBling(T,e)){}
    else printf("ERROR"); 
    printf("\n");
	
	
	break;
case 5:
	printf("输入一个叶子查找双亲:");
    scanf(" %c",&e);
    printf("%c的双亲是 :",e);
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
printf("****************图的基本操作及应用******************\n");
printf("* 1  创建无向图                                    *\n");
printf("* 2  创建无向网                                    *\n");
printf("* 3  创建有向图                                    *\n");
printf("* 4  创建有向网                                    *\n");
printf("* 5  图的遍历                                      *\n");
printf("* 6  最小生成树                                    *\n");
printf("* 7  拓扑排序                                      *\n");
printf("* 8  最短路径                                      *\n");
printf("* 9  关键路径                                      *\n");
printf("* 10 退出                                          *\n");
printf("****************************************************\n");
printf("请选择：");
fflush(stdin);
scanf(" %d",&n);
switch(n){
case 1://创建无向图
	if(CreateUDG(G)){
	printMGraph(G);
	}
	break;
case 2://创建无向网
	if(CreateUDN(G)){
	printMGraph(G);
	}break;
case 3://创建有向图
    if(CreateDG(G)){
	printMGraph(G);
	}break;
case 4://创建有向网
    if(CreateDN(G)){
	printMGraph(G);
	}break;
case 5://图的遍历
    DFSTraverse(G);
    cout<<endl;
    BFSTraverse(G);
    cout<<endl;
	break;
case 6://最小生成树的生成
	//printf("输入节点开始生成最小生成树:\n");
	//char c;
	fflush(stdin);
	//scanf(" %c",&c);
	printf("最小生成树(从第一个节点开始):\n");
	MiniSpanTree_prim(G);
	break;
	
case 7://拓扑排序
	printf("创建一个AOV网，用来拓扑排序:\n");
	ALGraph G;
    CreateAOV(G);
	TopicalSort(G);
	break;
case 8://最短路径
    printf("最短路径(弗洛伊德算法):\n");
	MGraph g,f;
	char from,to;
	f=CreateDN_F(g);
	printf("输入求路径的两个顶点(中间不需要空格):\n");
	fflush(stdin);
	scanf("%c %c",&from,&to);
	ShortestPath(f,from,to);
	break;
case 9://关键路径
  
	ALGraph Ga;
	IntStack T;
	int ve[20];
	int vl[20];
	IntInitStack(T);
	printf("创建一个新的AOE网求关键路径：\n");
	CreateAOE(Ga);

	if(!TopologicalOrder(Ga,ve,T))
		printf("图中有环，操作失败!");
	else{
        printf("开始	结束	最早开始时间  最晚开始时间    用时	是否为关键活动\n");
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
printf("请选择：");
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
