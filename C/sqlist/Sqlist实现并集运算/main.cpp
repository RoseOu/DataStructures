#include <iostream>
#include "func.cpp"
using namespace std;

void InputElement(SqList &L)   
{
	int i, num, e;
	
	printf("num  = ");
	scanf("%d", &num);
	printf("elem = ");
	for(i = 1; i <= num; i++)
	{
		scanf("%d", &e);
		ListInsert_Sq(L, i, e); 
	}
}

void Union(SqList La, SqList Lb, SqList &Lc)
{
	int i, j = 0;
	ElemType e;

	for (i = 1; i <= ListLength_Sq(La); i++)
	{
		GetElem_Sq(La, i, e);
		j++;
		ListInsert_Sq(Lc, j, e);
	}
	for (i = 1; i <= ListLength_Sq(Lb); i++)
	{
		GetElem_Sq(Lb, i, e);
		if (LocateElem_Sq(Lc, e))
			continue;
		j++;
		ListInsert_Sq(Lc, j, e);
	}
} 

int main()
{
	SqList La, Lb, Lc;
	
	printf("************* Input A ***************\n");
	InitList_Sq(La);
	InputElement(La);

	printf("************* Input B ***************\n");
	InitList_Sq(Lb);
	InputElement(Lb);

	InitList_Sq(Lc);
	
	Union(La,Lb,Lc);

	printf("\n************* Result ****************\n");
	printf("A = {");
	ListTraverse_Sq(La);
	printf("}\n"); 

	printf("B = {");
	ListTraverse_Sq(Lb);
	printf("}\n"); 

	printf("A U B = {");
	ListTraverse_Sq(Lc);
	printf("}\n"); 
	printf("*************************************\n");

	DestroyList_Sq(La);
	DestroyList_Sq(Lb);
	DestroyList_Sq(Lc);

	return 1;
}