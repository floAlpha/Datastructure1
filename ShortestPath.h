#include<stdio.h>  
#define MAX_VERTEX_NUM 20  
/*�����·��*/
MGraph CreateDN_F(MGraph &G){ 
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
		for(k=0;k<G.arcnum;k++){
			printf("\n�������%d���� <v1 v2 w>:",k+1);
			fflush(stdin);
			scanf(" %c%c%d",&v1,&v2,&w);
			i=LocateVex(G,v1);
			j=LocateVex(G,v2);
			G.arcs[i][j].adj=w;
		}
		return G;
		
}//����������

  
//���������㷨  
void ShortestPath(MGraph &g,char from1,char to1)  
{   int from = from1-'a';
    int to = to1 - 'a';
    int i,j,k;  
    int shortestPath[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�洢���·��������  
    //��ʼ��shortestPath  
	
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
        }   //����������˳�μ��룬���޸����·��  
   
    for(k=0;k<g.vexnum;k++){  
        //��i��j֮�����k  
        for(i=0;i<g.vexnum;i++){  
            for(j=0;j<g.vexnum;j++){  
                if(shortestPath[i][k]+shortestPath[k][j]<shortestPath[i][j])  
                   shortestPath[i][j]=shortestPath[i][k]+shortestPath[k][j]; 
            }  
        }  
    }  
    //������·��  
    if(shortestPath[from][to]==1000){ 
        printf("%c��%cû��·��\n",from+'a',to+'a');  
    }  
	else{
    printf("%c��%c�����·�������ǣ�%d\n",from+'a',to+'a',shortestPath[from][to]);  
    printf("\n");  
	}
}  
