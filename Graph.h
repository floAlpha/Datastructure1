#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include <iomanip>
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

/*����ͼ�Ļ���������������С�������Ľ�����*/

using namespace std;

typedef struct QNode{
   int data;
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

int EnQueue(LinkQueue &Q,int e){
// �ڶ�β����Ԫ��
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(0);
    p->data=e;p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return 1;
}

char DeQueue(LinkQueue &Q,int &e){
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
}MGraph;//����ͼ����������


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
printf("�����������ڵ���:");
scanf(" %d",&G.vexnum);
printf("��������������:");
scanf(" %d",&G.arcnum);
printf("�����������ڵ�:");
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
printf("\n�����%d���� <v1 v2 w>:",k+1);
fflush(stdin);
scanf(" %c%c%d",&v1,&v2,&w);
i=LocateVex(G,v1);
j=LocateVex(G,v2);
G.arcs[i][j].adj=w;
G.arcs[j][i]=G.arcs[i][j];
}
return 1;
}//������


int CreateDG(MGraph &G){ 
   int v1,v2,i,j,k;

cout<<"��������ͼ�ڵ���:";
cin>>G.vexnum;
//cout<<endl;
cout<<"��������ͼ����:";
cin>>G.arcnum;
//cout<<endl;
cout<<"��������ͼ�ڵ�:";
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
      printf("\n��������ͼ��%d���� <v1 v2>:",k+1);
	  fflush(stdin);
	  scanf(" %c%c",&v1,&v2);
  //    cin>>v1>>v2;
	  i=LocateVex(G,v1);j=LocateVex(G,v2);
	  G.arcs[i][j].adj=1; 
   }
return 1;
}//����ͼ



int CreateDN(MGraph &G){ 
int i,j,k,w;
char v1,v2;
printf("�����������ڵ���:");
scanf(" %d",&G.vexnum);
printf("��������������:");
scanf(" %d",&G.arcnum);
printf("�����������ڵ�:");
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
printf("\n�������%d���� <v1 v2 w>:",k+1);
fflush(stdin);
scanf(" %c%c%d",&v1,&v2,&w);
i=LocateVex(G,v1);
j=LocateVex(G,v2);
G.arcs[i][j].adj=w;
//G.arcs[j][i]=G.arcs[i][j];
}
return 1;

}//����������


int CreateUDG(MGraph &G){ 
int v1,v2,i,j,k;

cout<<"��������ͼ�ڵ���:";
cin>>G.vexnum;
cout<<endl;
cout<<"��������ͼ����:";
cin>>G.arcnum;
cout<<endl;
cout<<"��������ͼ�ڵ�:";
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
      printf("\n��������ͼ��%d���� <v1 v2>:",k+1);
	  fflush(stdin);
	  scanf(" %c%c",&v1,&v2);
  //    cin>>v1>>v2;
	  i=LocateVex(G,v1);j=LocateVex(G,v2);
	  G.arcs[i][j].adj=1; 
	  G.arcs[j][i]=G.arcs[i][j];
   }
return 1;
}//��������ͼ

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
}//��һ���ڵ�

int NextAdjVex(MGraph G,int v,int w)  
{  
    int i;  
    for( i = w+1; i<G.vexnum; i++)//+1  
        if(G.arcs[v][i].adj) return i;  
		if(i == (G.vexnum -1)) {return -1; } 
    return -1;  
  
}  //��һ���ڵ�



void visitVex(MGraph G, int v){  
    cout<<G.vers[v]<<" ";  
}  


void DFS(MGraph G,int v){//�����������DFS
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
  cout<<"��������������Ϊ��";
  for(v=0;v<G.vexnum;){visited[v]=false;v++;}
  for(v=0;v<G.vexnum;){
	  if(!visited[v]) {DFS(G,v);}
	  v++;}
}

//�����������BFS
void BFSTraverse(MGraph &G){
int u,v,w;
LinkQueue Q;
for(v=0;v<G.vexnum;++v){visited[v]=false;}
	InitQueue(Q);
	cout<<"��������������Ϊ��";
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
    cout<<"�ڽӾ����Ѿ��������ڽӾ���Ϊ��"<<endl;  
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
            else cout<<"��"<<" "; 
        cout<<endl;  
    }  
} //��ͼ���ڽӾ���

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
closedge[k].lowcost = 0;  //��һ��������뼯��

  for(i=1;i<G.vexnum;i++) //�γ�n-1���ߵ������� 
  {
  int min=INFINITY; 

  for(j=1;j<G.vexnum;j++) 
	  if((closedge[j].lowcost<min)&&(closedge[j].lowcost!=0)) 
	  {
		  min=closedge[j].lowcost; 
		  temp=j;
	  }
        
  printf("%c  %c  %d\n",closedge[temp].adjvex,G.vers[temp],closedge[temp].lowcost);
  closedge[temp].lowcost=0;//��temp���ڵ���뼯��
	cost+=min;

	for (j =1;j<G.vexnum ; j++)
	{
		if( G.arcs[temp][j].adj < closedge[j].lowcost){
			closedge[j].adjvex = G.vers[temp];
		    closedge[j].lowcost = G.arcs[temp][j].adj;
		}
	}
		
 
  }
  printf("��ʹ���Ϊ: %d\n",cost); 
}

