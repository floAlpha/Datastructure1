#include<stdio.h>

#define maxsize 100

typedef struct{
int i,j;
int val;
}Triple;

typedef struct{
Triple data[maxsize+1];
int mu,nu,tu;
}TSMatrix; //三元组类型

int InitSMatrix(TSMatrix &M){
for(int i=0;i<2;i++)
  M.data[i].i=0;
  M.data[i].j=0;
  M.mu=M.nu=2;
  M.tu=0;
  return 1;
}

int CreateSMatrix(TSMatrix &M){
int row,col,e;
cout<<"输入行数  列数  元素数 :";
cin>>M.mu;
cin>>M.nu;
cin>>M.tu;

if(M.tu>maxsize) return 0;
else {
printf("row col e:\n");
for(int k=1;k<=M.tu;k++){
scanf("%d %d %d",&row,&col,&e);

  M.data[k].i=row;
  M.data[k].j=col;
  M.data[k].val=e;
}
return 1;
}
}/*以三元组方式创建矩阵*/



int AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q){//加法计算函数
	if((M.mu<=0)||(M.nu<=0)||(M.tu<=0)||(N.mu<=0)||(N.nu<=0)||(N.tu<=0)){
		printf("格式错误"); 
        return 0;    }
	if(M.mu!=N.mu||M.nu!=N.nu){ 
		printf("格式错误"); 
		return 0;    }
	else {
	Q.mu=M.mu;    
	Q.nu=M.nu;   
	Q.tu=0;    
	int x=0,y=0;    
	for(int i=1;i<=M.mu;i++){         
		for(int j=1;j<=N.nu;j++){   
			for(int p=1;p<=M.tu;p++){  
				if(i==M.data[p].i&&j==M.data[p].j){   
					x=M.data[p].val;  
					break;  
				}     else x=0;       
			}//for p         
			for(int q=1;q<=N.tu;q++){     
				if(i==N.data[q].i&&j==N.data[q].j){
					y=N.data[q].val; 
					break;                
				}     
				else y=0;             
			}//for q         
			if((x+y)!=0){                     
				Q.data[Q.tu+1].i=i;   
				Q.data[Q.tu+1].j=j;
				Q.data[Q.tu+1].val=x+y;
				Q.tu++;       
			}//if  
		}//for j   
	}//for i 
 return 1;
	}
}

/*
int MultiSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q){//乘法计算函数
	if((M.mu<=0)||(M.nu<=0)||(M.tu<=0)||(N.mu<=0)||(N.nu<=0)||(N.tu<=0)){
		printf("格式错误"); 
		return 0;    }
	else if(M.mu!=N.nu) {
		printf("格式错误");      
		return 0;    }
	else
	{
		Q.mu=N.mu;    
		Q.nu=M.nu;   
		Q.tu=0;
		int i,j;
		int x=0,y=0;  
		int m[10],n[10],count,k=1,Sum=0;
		int temp1[10],temp2[10];
		temp1[0]=temp2[0]=0;
		for (i=1;i<=M.tu;i++){
			for (j=1;j<=N.tu;j++){
				for (int p=1;p<=M.mu;p++)
				{
					if (M.data[i].i++==N.data[p].j&&M.data[i].j==N.data[p].i++){
				
						count=M.data[i].val*N.data[j].val;			
						temp1[k]=M.data[i].i;
						temp2[k]=N.data[j].j;
						m[k]=M.data[i].i;
						n[k]=N.data[j].j;
						k++;	
					} 
				}
			if(temp1[k-1]==temp1[k-2]&&temp2[k-1]==temp2[k-2]){	Sum+=count;	}	
			else{	Sum=0;	Sum+=count;		}		
			if(Sum!=0){      
				Q.data[Q.tu+1].i=m[k-1];
				Q.data[Q.tu+1].j=n[k-1];
				Q.data[Q.tu+1].val=Sum;
				Q.tu++; 
			}  
			if(Q.data[Q.tu-1].i==Q.data[Q.tu].i&&Q.data[Q.tu-1].j==Q.data[Q.tu].j)
			{
				Q.data[Q.tu-1].i=Q.data[Q.tu].i;
				Q.data[Q.tu-1].j=Q.data[Q.tu].j;
				Q.data[Q.tu-1].val=Q.data[Q.tu].val;
				Q.tu--; 
			}
			}

		}
	  
	}
    return 1;
}
*/

int MultiSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q){
  int k,p,q,crow,brow,ccol;
  
  int num[maxsize],pos[maxsize],Sum[maxsize];
  if (M.nu==N.mu&&M.mu*N.nu!=0)
  { 
	  for(k=1;k<=N.mu;k++) {	num[k]=0;	}				//数组置零   
      for(k=1;k<=N.tu;k++) {	num[N.data[k].i]++;   }		//记录三元组下标
      pos[1]=1;
	  for(k=2;k<=N.tu;k++){	//初始化三元组Q
            pos[k]=pos[k-1]+num[k-1];          //pos指定相乘的位置每一行每一列的第pos位置元素要相乘
            pos[1+N.tu]=pos[N.tu]+1;		   //pos后移一个位置	
            Q.mu=M.mu;Q.nu=N.nu; Q.tu=0; p=1;
	  }
      while(p<=M.tu){		//乘法开始
		crow=M.data[p].i;        //crow指向M的第p个元素的行

        for(k=1;k<=Q.nu;k++){   Sum[k]=0;	} //M的每一行开始乘法前，每一行乘以每一列的计数器归零

        while (p<=M.tu&&M.data[p].i==crow){
            brow=M.data[p].j;		//brow指向M的第p个元素的列

            for(q=pos[brow];q<=pos[brow+1]-1;q++)//如果pos小于N的列数
            {	ccol=N.data[q].j;
				Sum[ccol]=Sum[ccol]+M.data[p].val*N.data[q].val;
			}
                p=p+1;    
		}
        for(ccol=1;ccol<=N.nu;ccol++)
           if(Sum[ccol]!=0){ 
			   Q.tu=Q.tu+1;
               Q.data[Q.tu].i=crow;
               Q.data[Q.tu].j=ccol;
               Q.data[Q.tu].val=Sum[ccol];
		   }
	  } 
	return 1;
  }
  else {
	  printf("格式错误");
	  return 0;
  }
}


int SubSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q){//减法计算函数
	if((M.mu<=0)||(M.nu<=0)||(M.tu<=0)||(N.mu<=0)||(N.nu<=0)||(N.tu<=0))
	{
		printf("格式错误"); 
        return 0;    
	}
	if(M.mu!=N.nu)
	{     
		printf("格式错误"); 
		return 0;	
	}   
	else {
	Q.mu=M.mu;    
	Q.nu=M.nu;   
	Q.tu=0;    
	int x=0,y=0;    
	for(int i=1;i<=Q.mu;i++){         
		for(int j=1;j<=Q.nu;j++){     
			for(int p=1;p<=M.tu;p++){  
				if((i==M.data[p].i)&&(j==M.data[p].j)){   
					x=M.data[p].val;   
					break;                
				}     else x=0;       
			}//for p         
			for(int q=1;q<=N.tu;q++){     
				if((i==N.data[q].i)&&(j==N.data[q].j)){
					y=N.data[q].val; 
					break;                
				}     
				else y=0;             
			}//for q         
			if(x-y!=0)
			{             
				Q.data[Q.tu+1].i=i;   
				Q.data[Q.tu+1].j=j;
				Q.data[Q.tu+1].val=x-y;
				Q.tu++;       
			}
		}//for j   
	}//for i 
 return 1;
	}
}
void output(TSMatrix &M)
 {  int i,j,t=1;
    printf("实际矩阵: \n");
  for(i=1;i<=M.mu;i++){
     for(j=1;j<=M.nu;j++){
		 if(M.data[t].i==i&&M.data[t].j==j)
		 { 
		    printf("%d ",M.data[t].val);
		   	t++;
		 }
            else printf("0 ");
	 }
      printf("\n");
    
  }
}
void PrintSMatrix(TSMatrix M){
	printf("三元组存储形式为：\n");
	for(int i=1;i<=M.tu;i++){
		printf("%d  %d  %d\n",M.data[i].i,M.data[i].j,M.data[i].val);	
	}
}