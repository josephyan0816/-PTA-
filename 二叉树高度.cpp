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
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
BinTree CreatBinTree()
{
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
	return BT[0];
}
int GetHeight( BinTree BT )
{
	int HL,HR,MaxH;
	if(BT)
	{
		HL=GetHeight(BT->Left);
		HR=GetHeight(BT->Right);
		MaxH=HL>HR?HL:HR;
		return(MaxH+1);
	}
	
	else return 0;
	
}
