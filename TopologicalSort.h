#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#define MAX_VERTEX_NUM 20
#define MAX_QUEUE_NUMBER 20
/*�ٽӱ�ṹ�������������ؼ�·��*/


typedef struct ArcNode
{
	int adjvex;//��ͷ�ڵ�
	double adj;//Ȩֵ
	int info;//���������Ϣ
	struct ArcNode *nextarc;
}ArcNode;//�ٽӱ�ڵ�

typedef struct VexNode
{
	char data;
	ArcNode *firstarc;
}VexNode,AdjList[MAX_VERTEX_NUM];//�ٽӱ��ͷ�ڵ�

typedef struct 
{
	AdjList vexs;
	int vexnum,arcnum;
}ALGraph;


/*
typedef struct{//�������
	int *elem;
	int front, rear;
}Queue;

void InitQueue(Queue &Q)
{
	Q.elem = new int[MAX_QUEUE_NUMBER];
	Q.front = Q.rear = 0;
}
int EmptyQueue(Queue Q)
{
	if(Q.front==Q.rear)
		return 0;
	else 
		return 1;
}
void DestroyQueue(Queue &Q){
	delete []Q.elem;
	Q.front = Q.rear = 0;
}

void EnterQueue(Queue &Q, int e)
{
	if((Q.rear + 1)%MAX_QUEUE_NUMBER != Q.front)
		Q.elem[Q.rear ]	= e;
	else
		printf("������!\n");
	Q.rear = (Q.rear + 1)%MAX_QUEUE_NUMBER;
}
void LeaveQueue(Queue &Q, int &e)
{
	if(Q.rear != Q.front)
		e = Q.elem[Q.front];
	else
		printf("���п�!\n");
	Q.front = (Q.front+1)%MAX_QUEUE_NUMBER;
}

void DFS(ALGraph G,char name,int *visited)
{
	int v,w; 
	ArcNode *p;
	v=LocateVex(G,name);
	visited[v]=1;
	printf("%c ",G.vexs[v].data);
	p=G.vexs[v].firstarc;
	while(p!=NULL)
	{
		w=p->adjvex;
		if(visited[w]==0)
			DFS(G,G.vexs[w].data,visited);
		p=p->nextarc;
	}

}
void DFSTravel(ALGraph G,char name)
{
	int v,k=0;
	int visited[20];
	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	for(v=LocateVex(G,name);k!=2;v=(v+1)%(G.vexnum-1))
	{
		if(v+1==LocateVex(G,name))
			k++;
		if(visited[v]==0)
			DFS(G,G.vexs[v].data,visited);
		
	}
}

void BFSTravel(ALGraph G,char name)
{
	ArcNode *p;
	int v,w,u,k=0;
    Queue Q;
	int visited[20];
	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	InitQueue(Q);
	for(v=LocateVex(G,name);k!=2;v=(v+1)%(G.vexnum-1))
	{
		if(v+1==LocateVex(G,name))
			k++;
		if(visited[v]==0)
		{
			visited[v]=1;
			printf("%c ",G.vexs[v].data);
			EnterQueue(Q,v);
			while(EmptyQueue(Q)!=0)
			{
				LeaveQueue(Q,u);
				p=G.vexs[u].firstarc;
				while(p!=NULL)
				{
					w=p->adjvex;
					if(visited[w]==0)
					{
						printf("%c ",G.vexs[w].data);
						visited[w]=1;
						EnterQueue(Q,w);
					}
					p=p->nextarc;
				}
			}
		}
	}
}
*/

int LocateVex(ALGraph G,char name)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(name-G.vexs[i].data==0)
			return i;
		return -1;
}

void CreateAOV(ALGraph &G){//��������
  ArcNode *p;
  char name1,name2;
  int i,j,k;
 // double w;
  printf("�����붥�����ͻ�����");
  scanf("%d%d",&G.vexnum,&G.arcnum);
  printf("���������붥������\n");
  for(i=0;i<G.vexnum;i++)
  {
		scanf(" %c",&G.vexs[i].data);
		G.vexs[i].firstarc=NULL;
		}
		for(k=0;k<G.arcnum;k++)
		{
		printf("����������ߣ�");
		scanf(" %c%c",&name1,&name2);
		i=LocateVex(G,name1);
		j=LocateVex(G,name2);
		p=new ArcNode;
		p->adjvex=j;
	//	p->adj=w;
		p->nextarc=G.vexs[i].firstarc;
		G.vexs[i].firstarc=p;
		}
}
	
		


void FindIndegree(ALGraph G, int indegree[])//�󶥵����� 
{   for(int i=0; i<G.vexnum; i++) 
    indegree[i]=0; 
    for(i=0; i<G.vexnum; i++) 
	{
       while(G.vexs[i].firstarc) 
	   { 
	      indegree[G.vexs[i].firstarc->adjvex]++; 
		  G.vexs[i].firstarc=G.vexs[i].firstarc->nextarc;
	   } 
	} 
} 

void TopicalSort(ALGraph G)   
{
    int indegree[40];
    int i, k, n;
    int count=0;                         //��ʼ�����������
    ArcNode *p;
    IntStack S;
    FindIndegree(G,indegree);
    IntInitStack(S);

    for(i=0;i<G.vexnum;i++)                      //���Ϊ0�Ķ�����ջ
	{
		if(!indegree[i])
			IntPush(S,i);
	}
    printf("\n\n������������Ϊ:");    
    while(!IntStackEmpty(S))                       //ջ��Ϊ��
	{
		IntPop(S,n);                             //����ջ��                
		printf("%c  ",G.vexs[n].data);      
		count++;
		for(p=G.vexs[n].firstarc;  p!=NULL;p=p->nextarc)//n�Ŷ����ÿ���ڽӵ���ȼ�1
		{
			k=p->adjvex;
			if(!(--indegree[k]))      //����ȼ�Ϊ�㣬������ջ
			{
				IntPush(S,k);
			}
		}
		
	}
    if(count<G.vexnum)//���������С��ԭʼͼ�Ķ�����������ͼ���л�·
	{
		printf("����ʧ�ܣ������л�·!\n\n");
	}
}



int TopologicalOrder(ALGraph G,int ve[],IntStack &T){
	int i,j,k;
	int count =0;
	//int ve[20];
	for ( i=0;i<G.vexnum;i++)
	{
		ve[i]=0;
	}
	int indegree[20];
	IntStack S;
	IntInitStack(S);
	FindIndegree(G,indegree);
    for (i =0;i<G.vexnum;i++)
    {
		if(!indegree[i])
			IntPush(S,i);
    }
	while (!IntStackEmpty(S))
	{
		IntPop(S,j);
		IntPush(T,j);
		++count;
		ArcNode *p;//�����ٽӱ�Ǳ�ͷ�ڵ�
		for (p=G.vexs[j].firstarc;p!=NULL;p=p->nextarc)
		{
			k=p->adjvex;
			if(--indegree[k]==0)
				IntPush(S,k);
			if(ve[j] + p->adj > ve[k])
				ve[k] = ve[j] + p->adj;
		}//for
	}//while
	
	if (count<G.vexnum)
		return 0;
	else 
		return 1;
}

void CreateAOE(ALGraph &G)//��ؼ�·��
{
	ArcNode *p;
	char name1,name2;
	int i,j,k;
	double w;
	printf("�����붥������");
	scanf("%d",&G.vexnum);
	printf("�����뻡����");
	scanf("%d",&G.arcnum);
	printf("���������붥������\n");
	for(i=0;i<G.vexnum;i++)
	{
		scanf(" %c",&G.vexs[i].data);
		G.vexs[i].firstarc=NULL;
	}
	for(k=0;k<G.arcnum;k++)
	{
		printf("���������ڵ��������㼰·������");
		scanf(" %c%c%lf",&name1,&name2,&w);
		i=LocateVex(G,name1);
		j=LocateVex(G,name2);
		p=new ArcNode;
		p->adjvex=j;
		p->adj=w;
		p->nextarc=G.vexs[i].firstarc;
		G.vexs[i].firstarc=p;
	}
}

void CriticalPath(ALGraph G,int ve[],int vl[],IntStack &T){
	int i,j,k,m;
	int dut,ee,el;
	char tag;
    j=ve[0];

    for(i=1;i<G.vexnum;i++) // j=Max(ve[]) ��ɵ��ֵ

     if(ve[i]>j)

       j=ve[i];

   for(i=0;i<G.vexnum;i++) // ��ʼ�������¼�����ٷ���ʱ��(���ֵ)

       vl[i]=j; // ��ɵ�����緢��ʱ��
	ArcNode *p;
	while (!IntStackEmpty(T))
	{
		for(IntPop(T,m),p=G.vexs[m].firstarc;p!=NULL;p=p->nextarc)
		{
			k=p->adjvex;
			dut = p->adj;
			if(vl[k] - dut < vl[m])
				vl[m]=vl[k]-dut;
		}//for
	}//while
		for (j=0;j<G.vexnum;j++)
		{
			for(p=G.vexs[j].firstarc; p!=NULL; p=p->nextarc){
				k=p->adjvex;
			    dut=p->adj;
				ee = ve[j];
				el= vl[k]-dut;
				tag = (ee==el)?'*':' ';
				printf(" %c	  %c	     %d		%d		%d	   ",G.vexs[j].data,G.vexs[k].data,ee,el,dut);
				if(tag-'*'==0)printf("�ؼ�·��\n");
				else printf("�ؼ�·��\n");
			}
		}
}//�ؼ�·��