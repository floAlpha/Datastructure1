#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
char data;
struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int CreateBiTree(BiTree &T){
char ch;
ch=getchar();
if(ch==' ') T=NULL;
else{
	if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(0);
	T->data=ch;
	CreateBiTree(T->lchild);
	CreateBiTree(T->rchild);
}
return 1;
}//以先序方式创建二叉树


int PreOrderTraverse(BiTree &T,int (*Visit)(char e)){
	if(T){
	if(Visit(T->data))
	   if(PreOrderTraverse(T->lchild,Visit))
		 if(PreOrderTraverse(T->rchild,Visit)) return 1;
	return 0;
	}
   else return 1;
}//先序遍历二叉树


int InOrderTraverse(BiTree &T,int (*Visit)(char e)){
	if(T){
	if(InOrderTraverse(T->lchild,Visit))
		if(Visit(T->data))
	       if(InOrderTraverse(T->rchild,Visit)) return 1;
	return 0;
	}
    else return 1;
}//中序遍历二叉树

int PostOrderTraverse(BiTree &T,int (*Visit)(char e)){
	if(T){
	if(PostOrderTraverse(T->lchild,Visit))
		if(PostOrderTraverse(T->rchild,Visit))
			if(Visit(T->data)) return 1;
	return 0;
	}
    else return 1;
}//后序遍历二叉树



void CountLeaf(BiTree &T,int &count){
	if(T){
	if((T->lchild==NULL)&&(T->rchild==NULL))
	count++;
	CountLeaf(T->lchild,count);
	CountLeaf(T->rchild,count);	
	}
}//计算叶子节点个数

int max(int a,int b){
	return a>b?a:b;
}

int Depth(BiTree &T){
   if(!T) return 0;
   else {
	return 1+max(Depth(T->lchild),Depth(T->rchild));
   }
} //求树的深度 



int Print(char e){
 printf("%c",e);
 return 1;
} //访问结点为输出其值（visit函数调用）

int LeftChild(BiTree T,char e){
    if (T&&T->lchild){
		if(T->data==e){
           Print(T->lchild->data);
		   return 1;
		}
		LeftChild(T->lchild,e);
		LeftChild(T->rchild,e);
		return 1;
	}
    return 0;	   
}


int RightChild(BiTree T,char e){
     if (T&&T->rchild){
		 if(T->data==e){
			 Print(T->rchild->data);
			 return 1;}
		RightChild(T->lchild,e);
	  	RightChild(T->rchild,e);
		return 1;
	}
     return 0; 	   
}

int LeftSiBling(BiTree T,char e)
{
	if(T&&T->lchild&&T->rchild)
	{
		if(T->lchild->data==e)
		{
			return 0;
		}
		else if(T->rchild->data==e)
		{

			 Print(T->lchild->data);
			 return 1;
		}
	 	     else
			 {
	    	 LeftSiBling(T->lchild,e);
	         LeftSiBling(T->rchild,e);
	
			 }
    
	}
	return 0;
}


int RightSiBling(BiTree T,char e)
{
	if(T&&T->lchild&&T->rchild)
	{
	   	if(T->rchild->data==e)
		{
		return 0;
		}// 
		 else if(T->lchild->data==e)
		 {
		   	 Print(T->rchild->data);
             return 1;
		 }
		  else
		  {
	    	RightSiBling(T->lchild,e);
	        RightSiBling(T->rchild,e);
		  }  
	}
	return 0;
}


int Parent(BiTree T,char e){
    if(T->rchild){
		if(e==T->rchild->data){
			Print(T->data);
			return 1;}
		else{
			Parent(T->lchild,e);
			Parent(T->rchild,e);

			}	
		}
	if (T->lchild)
	{
		if(e==T->lchild->data){
		Print(T->data);
		return 1;
		}
		else{
			Parent(T->lchild,e);
			Parent(T->rchild,e);
			return 1;
		}		
	}
	return 0;     
}

