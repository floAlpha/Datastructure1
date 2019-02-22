#include<stdio.h>  
#define MAX_VERTEX_NUM 20  
/*求最短路径*/
MGraph CreateDN_F(MGraph &G){ 
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
		for(k=0;k<G.arcnum;k++){
			printf("\n请输入第%d条边 <v1 v2 w>:",k+1);
			fflush(stdin);
			scanf(" %c%c%d",&v1,&v2,&w);
			i=LocateVex(G,v1);
			j=LocateVex(G,v2);
			G.arcs[i][j].adj=w;
		}
		return G;
		
}//创建有向网

  
//弗洛伊德算法  
void ShortestPath(MGraph &g,char from1,char to1)  
{   int from = from1-'a';
    int to = to1 - 'a';
    int i,j,k;  
    int shortestPath[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//存储最短路径的数组  
    //初始化shortestPath  
	
    for(i=0;i<g.vexnum;i++)  
        for(j=0;j<g.vexnum;j++){  
            if(i==j){  
                shortestPath[i][j]=0;  
            }  
            if((g.arcs[i][j].adj>0) && (g.arcs[i][j].adj<1000)) 
			{
				shortestPath[i][j] = g.arcs[i][j].adj; 
			}
            else 
				shortestPath[i][j]=1000;
			//printf("%d\n",shortestPath[i][j]);
        }   //将各个顶点顺次加入，并修改最短路径  
   
    for(k=0;k<g.vexnum;k++){  
        //在i，j之间加入k  
        for(i=0;i<g.vexnum;i++){  
            for(j=0;j<g.vexnum;j++){  
                if(shortestPath[i][k]+shortestPath[k][j]<shortestPath[i][j])  
                   shortestPath[i][j]=shortestPath[i][k]+shortestPath[k][j]; 
            }  
        }  
    }  
    //输出最短路径  
    if(shortestPath[from][to]==1000){ 
        printf("%c到%c没有路径\n",from+'a',to+'a');  
    }  
	else{
    printf("%c到%c的最短路径长度是：%d\n",from+'a',to+'a',shortestPath[from][to]);  
    printf("\n");  
	}
}  
