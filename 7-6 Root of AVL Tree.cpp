#include<stdio.h>
#include<stdlib.h>
typedef struct AVLNode *Position ;
typedef Position AVLTree ;
typedef struct AVLNode{
	int data;
	AVLTree left;
	AVLTree right;
	int height;
	
};
int GetHeight(Position T);
AVLTree SingleRightRotation(AVLTree A);
AVLTree SingleLeftRotation(AVLTree A);
AVLTree Insert(AVLTree T,int x);
AVLTree DoubleRightLeftRotation(AVLTree A);
AVLTree DoubleLeftRightRotation(AVLTree A);
int Max(int a,int b);
int GetHeight(Position T)
{
	if(T==NULL)return -1;
	else return T->height;
}
int Max(int a,int b)
{
	return a>b?a:b;
}
AVLTree Insert(AVLTree T,int x)
{
	if(T==NULL)
	{
		T=(AVLTree)malloc(sizeof(struct AVLNode));
		T->data=x;
		T->height=1;
		T->left=NULL;
		T->right=NULL;		
		
		}
	else if(x<T->data)
	{
		T->left=Insert(T->left,x);
	if(GetHeight(T->left)-GetHeight(T->right)==2)
		if(x<T->left->data)
			T=SingleLeftRotation(T);
		else 
			T=DoubleLeftRightRotation(T);
	}
	else if(x>T->data)
	{
		T->right=Insert(T->right,x);
		if(GetHeight(T->left)-GetHeight(T->right)==-2)
			if(x>T->right->data)
				T=SingleRightRotation(T);
			else
				T=DoubleRightLeftRotation(T);	
		
	 } 
	T->height=Max(GetHeight(T->left),GetHeight(T->right))+1;
	return T;				
}
AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B=A->left;
	A->left=B->right;
	//B->right=A;
	A=B->right;
	A->height=Max(GetHeight(A->left),GetHeight(A->right))+1;
	B->height=Max(GetHeight(B->left),A->height)+1;
	return B;
}
AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B=A->right;
	A->right=B->left;
	//B->left=A;
	A=B->left;
	A->height=Max(GetHeight(A->left),GetHeight(A->right))+1;
	B->height=Max(GetHeight(B->right),A->height)+1;
	return B;
	
}
AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->left=SingleRightRotation(A->left);
	return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->right=SingleLeftRotation(A->right);
	return SingleRightRotation(A);
}
int main()
{
	int n;
	int num;
	AVLTree T=NULL;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&num);
		T=Insert(T,num);
		n--;
	}
	if(T!=NULL)printf("%d",T->data);
}
