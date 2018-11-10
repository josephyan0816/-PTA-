#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* ÊµÏÖÏ¸½ÚºöÂÔ */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
BinTree CreatBinTree(){
	BinTree BT[9];
	int i;
	for(i=0;i<9;i++)
	{
		BT[i]=(BinTree)malloc(sizeof(struct TNode));
		BT[i]->Data=(char)(65+i);
	}
	BT[0]->Left=BT[1];
	BT[0]->Right=BT[2];
	BT[1]->Left=BT[3];
	BT[1]->Right=BT[5];
	BT[2]->Left=BT[6];
	BT[2]->Right=BT[8];
	BT[3]->Left=NULL;
	BT[3]->Right=NULL;
	BT[5]->Left=BT[4];
	BT[5]->Right=NULL;
	BT[6]->Left=NULL;
	BT[6]->Right=BT[7];
	BT[8]->Left=NULL;
	BT[8]->Right=NULL;
	BT[4]->Left=NULL;
	BT[4]->Right=NULL;
	BT[7]->Left=NULL;
	BT[7]->Right=NULL;
	return BT[0];
	
	
	}
void InorderTraversal( BinTree BT ){
	
	if(BT)
	{
		InorderTraversal(BT->Left);
		printf(" %c",BT->Data);
		InorderTraversal(BT->Right);
	}
	
	
	
}
void PreorderTraversal( BinTree BT ){
	
	if(BT)
	{
		printf(" %c",BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
	
	
}
void PostorderTraversal( BinTree BT ){
	
	if(BT)
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c",BT->Data);
	}
	
}
void LevelorderTraversal( BinTree BT ){
	
	BinTree q[100];
	BinTree p;
	int head=0;
	int tail=0;
	if(BT)
	{
		q[tail++]=BT;
		while(tail!=head)
		{
			p=q[head++];
			printf(" %c",p->Data);
			if(p->Left)	q[tail++]=p->Left;
			if(p->Right) q[tail++]=p->Right;
		}
		
	}
	
	
}	
