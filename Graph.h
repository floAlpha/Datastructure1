#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include <iomanip>
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

/*用于图的基本操作（包括最小生成树的建立）*/

using namespace std;

typedef struct QNode{
   int data;
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

int EnQueue(LinkQueue &Q,int e){
// 在队尾插入元素
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(0);
    p->data=e;p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return 1;
}

char DeQueue(LinkQueue &Q,int &e){
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

typedef enum{DG,DN,UDG,UDN} GraphKind;

typedef struct ArcCell{
int adj;
char *info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
char vers[MAX_VERTEX_NUM];
AdjMatrix arcs;
int vexnum,arcnum;
GraphKind kind;
}MGraph;//定义图的数据类型


int LocateVex(MGraph &G,char v){
int i;
for(i=0;i<G.vexnum;i++){
if(v==G.vers[i]) return i;
}
exit(0);
}

int CreateUDN(MGraph &G){
int i,j,k,w;
char v1,v2;
printf("输入无向网节点数:");
scanf(" %d",&G.vexnum);
printf("输入无向网边数:");
scanf(" %d",&G.arcnum);
printf("输入无向网节点:");
//fflush(stdin);
for(i=0;i<G.vexnum;i++){
scanf(" %c",&G.vers[i]);
}

for(i=0;i<G.vexnum;i++)
for(j=0;j<G.vexnum;j++){
	G.arcs[i][j].adj=INFINITY;
	G.arcs[i][j].info=NULL;
}

for(k=0;k<G.arcnum;k++){
printf("\n输入第%d条边 <v1 v2 w>:",k+1);
fflush(stdin);
scanf(" %c%c%d",&v1,&v2,&w);
i=LocateVex(G,v1);
j=LocateVex(G,v2);
G.arcs[i][j].adj=w;
G.arcs[j][i]=G.arcs[i][j];
}
return 1;
}//无向网


int CreateDG(MGraph &G){ 
   int v1,v2,i,j,k;

cout<<"输入有向图节点数:";
cin>>G.vexnum;
//cout<<endl;
cout<<"输入有向图边数:";
cin>>G.arcnum;
//cout<<endl;
cout<<"输入有向图节点:";
for (i=0;i<G.vexnum;i++)
{cin>>G.vers[i];}
//cout<<endl;
for(i=0;i<G.vexnum;i++){
   for (j=0;j<G.vexnum;j++){
	   G.arcs[i][j].adj=0;
       G.arcs[i][j].info=NULL;
   }
}
   for (k=0;k<G.arcnum;k++){
      printf("\n输入有向图第%d条边 <v1 v2>:",k+1);
	  fflush(stdin);
	  scanf(" %c%c",&v1,&v2);
  //    cin>>v1>>v2;
	  i=LocateVex(G,v1);j=LocateVex(G,v2);
	  G.arcs[i][j].adj=1; 
   }
return 1;
}//有向图



int CreateDN(MGraph &G){ 
int i,j,k,w;
char v1,v2;
printf("输入有向网节点数:");
scanf(" %d",&G.vexnum);
printf("输入有向网边数:");
scanf(" %d",&G.arcnum);
printf("输入有向网节点:");
//fflush(stdin);
for(i=0;i<G.vexnum;i++){
scanf(" %c",&G.vers[i]);
}

for(i=0;i<G.vexnum;i++)
for(j=0;j<G.vexnum;j++){
	G.arcs[i][j].adj=INFINITY;
	G.arcs[i][j].info=NULL;
}

for(k=0;k<G.arcnum;k++){
printf("\n请输入第%d条边 <v1 v2 w>:",k+1);
fflush(stdin);
scanf(" %c%c%d",&v1,&v2,&w);
i=LocateVex(G,v1);
j=LocateVex(G,v2);
G.arcs[i][j].adj=w;
//G.arcs[j][i]=G.arcs[i][j];
}
return 1;

}//创建有向网


int CreateUDG(MGraph &G){ 
int v1,v2,i,j,k;

cout<<"输入无向图节点数:";
cin>>G.vexnum;
cout<<endl;
cout<<"输入无向图边数:";
cin>>G.arcnum;
cout<<endl;
cout<<"输入无向图节点:";
for (i=0;i<G.vexnum;i++)
cin>>G.vers[i];
cout<<endl;
for(i=0;i<G.vexnum;i++){
   for (j=0;j<G.vexnum;j++){
	   G.arcs[i][j].adj=0;
       G.arcs[i][j].info=NULL;
   }
}
   for (k=0;k<G.arcnum;k++){
      printf("\n输入无向图第%d条边 <v1 v2>:",k+1);
	  fflush(stdin);
	  scanf(" %c%c",&v1,&v2);
  //    cin>>v1>>v2;
	  i=LocateVex(G,v1);j=LocateVex(G,v2);
	  G.arcs[i][j].adj=1; 
	  G.arcs[j][i]=G.arcs[i][j];
   }
return 1;
}//创建无向图

bool visited[40];
//int (*VisitFunc)(int v);

int FirstAdjVex(MGraph G,int v){
	for(int i=0;i<G.vexnum;i++){
	  if(G.arcs[v][i].adj)
		  return i;
	}
	if(i == G.vexnum){
		return -1;}
	return -1;
}//第一个节点

int NextAdjVex(MGraph G,int v,int w)  
{  
    int i;  
    for( i = w+1; i<G.vexnum; i++)//+1  
        if(G.arcs[v][i].adj) return i;  
		if(i == (G.vexnum -1)) {return -1; } 
    return -1;  
  
}  //下一个节点



void visitVex(MGraph G, int v){  
    cout<<G.vers[v]<<" ";  
}  


void DFS(MGraph G,int v){//深度优先搜索DFS
  visited[v]=true;
  visitVex(G,v);
 // VisitFunc(v);
  for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w)){
	 if(!visited[w])
		DFS(G,w);
  }
}

void DFSTraverse(MGraph G){
// VisitFunc=Visit;
  int v;
  cout<<"深度优先搜索结果为：";
  for(v=0;v<G.vexnum;){visited[v]=false;v++;}
  for(v=0;v<G.vexnum;){
	  if(!visited[v]) {DFS(G,v);}
	  v++;}
}

//广度优先搜索BFS
void BFSTraverse(MGraph &G){
int u,v,w;
LinkQueue Q;
for(v=0;v<G.vexnum;++v){visited[v]=false;}
	InitQueue(Q);
	cout<<"广度优先搜索结果为：";
	for (v=0;v<G.vexnum;++v){
		if(!visited[v]) visitVex(G,v);
		visited[v]=true;
		EnQueue(Q,v);
		while(!QueueEmpty(Q)){
		  DeQueue(Q,u);
		  
		  for(w=FirstAdjVex(G,u); w>=0; w=NextAdjVex(G,u,w)){
			  if(!visited[w]){
			    visited[w]=true;
				visitVex(G,w);
				EnQueue(Q,w);
			  }//if
		  }//for
		}//while
	}//for
}



void printMGraph(MGraph G){  
    cout<<"邻接矩阵已经创建，邻接矩阵为："<<endl;  
    cout<<"  ";
    for(int i=0;i<G.vexnum;i++){cout<<setw(2)<<G.vers[i]<<" ";}
    cout<<endl;
    for(i=0;i<G.vexnum;i++){ 
		cout<<G.vers[i]<<" ";
        for(int j=0;j<G.vexnum;j++)  
			if (G.arcs[i][j].adj!=INFINITY)
			{
				cout<<setw(2)<<G.arcs[i][j].adj<<" ";  
			}
            else cout<<"∞"<<" "; 
        cout<<endl;  
    }  
} //求图的邻接矩阵

struct Closedge
{  char adjvex;
   int lowcost;
};


void MiniSpanTree_prim(MGraph G){
Closedge closedge[MAX_VERTEX_NUM];
int i,j,k;
int cost=0;
int temp=0;
//k=LocateVex(G,u);
k=0;
for( j = 0; j<G.vexnum; ++j){
   if(j!=k)
	   closedge[j].adjvex=G.vers[k];
       closedge[j].lowcost=G.arcs[k][j].adj;

}
closedge[k].lowcost = 0;  //第一个定点进入集合

  for(i=1;i<G.vexnum;i++) //形成n-1条边的生成树 
  {
  int min=INFINITY; 

  for(j=1;j<G.vexnum;j++) 
	  if((closedge[j].lowcost<min)&&(closedge[j].lowcost!=0)) 
	  {
		  min=closedge[j].lowcost; 
		  temp=j;
	  }
        
  printf("%c  %c  %d\n",closedge[temp].adjvex,G.vers[temp],closedge[temp].lowcost);
  closedge[temp].lowcost=0;//第temp个节点进入集合
	cost+=min;

	for (j =1;j<G.vexnum ; j++)
	{
		if( G.arcs[temp][j].adj < closedge[j].lowcost){
			closedge[j].adjvex = G.vers[temp];
		    closedge[j].lowcost = G.arcs[temp][j].adj;
		}
	}
		
 
  }
  printf("最低代价为: %d\n",cost); 
}

