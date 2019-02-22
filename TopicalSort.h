#include<stdio.h>
//#include"AdjacencyList.h"
#include"IntStack.h"

 void FindIndegree(ALGraph G, int indegree[])//求顶点的入度 
 { for(int i=0; i<G.vexnum; i++) 
      indegree[i]=0; 
   for(i=0; i<G.vexnum; i++) 
   { ArcNode *p=G.vexs[i].firstarc; 
        while(p) 
		{ 
			indegree[p->adjvex]++; 
			p=p->nextarc; 
		} 
   } 
 } 

int TopicalSort(ALGraph G,int indegree[]){
	FindIndegree(G,indegree);
	int i;
	IntStack S;
	IntInitStack(S);
	for(i = 0;i<G.vexnum;++i)
	{	if(!indegree[i])
		IntPush(S,i);
	}
    int count=0;
	while (!IntStackEmpty(S))
	{   ArcNode p;
	    int k;
		IntPop(S,i);
		printf("%d  %c",i,G.vexs[i].data);
		++count;
		for( p=G.vexs->firstarc; p ;p=p->nextarc)
		{
			k = p->adjvex;
			if(!(--indegree[k]))
				IntPush(S,k);
		}//for
	}//while
   if (count<G.vexnum) return 0;
   else return 1;
}//TopicalSort
 