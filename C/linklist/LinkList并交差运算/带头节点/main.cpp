#include <iostream>
#include "func.cpp"
using namespace std;

void InputElement(LinkList &L)   //输入数据
{
	int i,num;
	
	printf("num  = ");
	cin >> num;
	printf("elem = ");
	for(i = 1; i <= num; i++)
	{
		LNode *e,*p=L->next;
		e=new LNode;
		cin >> e->data;
		ListInsert_L(L, p, e); 
	}
}

void Union(LinkList La, LinkList Lb, LinkList &Lc) //求并集
{
	LNode *p=La->next,*q=Lb->next;

	while (p!=NULL)
	{
		LNode *e,*r=Lc->next;
		e=new LNode;
		GetElem_L(La, p, e->data);
		ListInsert_L(Lc, r, e);
		p=p->next;
	}
	
	while (q!=NULL)
	{	
		LNode *e,*r=Lc->next;
		e=new LNode;

		GetElem_L(Lb, q, e->data);
		if (LocateElem_L(Lc, e->data))
			q=q->next;
		else
		{
			ListInsert_L(Lc, r, e);
			q=q->next;
		}
	}
}

void Inter(LinkList La, LinkList Lb, LinkList &Ld)  //求交集
{
	LNode *p=La->next,*q=Lb->next;

	while (p!=NULL)
	{	
		LNode *e,*r=Ld->next;
		e=new LNode;
		GetElem_L(La, p, e->data);
		if (LocateElem_L(Lb, e->data))
		{
			ListInsert_L(Ld, r, e);
		}
		p=p->next;
	}
}

void SubA(LinkList La, LinkList Lb, LinkList &Le)   //求差集(A-B)
{
	LNode *p=La->next,*q=Lb->next;

	while (p!=NULL)
	{	
		LNode *e,*r=Le->next;
		e=new LNode;

		GetElem_L(La, p, e->data);
		if (LocateElem_L(Lb, e->data))
			p=p->next;
		else
		{
			ListInsert_L(Le, r, e);
			p=p->next;
		}
	}
}

void SubB(LinkList La, LinkList Lb, LinkList &Lf)   //求差集(B-A)
{
	LNode *p=La->next,*q=Lb->next;

	while (q!=NULL)
	{	
		LNode *e,*r=Lf->next;
		e=new LNode;

		GetElem_L(Lb, q, e->data);
		if (LocateElem_L(La, e->data))
			q=q->next;
		else
		{
			ListInsert_L(Lf, r, e);
			q=q->next;
		}
	}
}

void main()
{
	LinkList La, Lb, Lc, Ld, Le, Lf;
	
	printf("************* Input A ***************\n");
	InitList_L(La);
	InputElement(La);

	printf("************* Input B ***************\n");
	InitList_L(Lb);
	InputElement(Lb);

	InitList_L(Lc);
	InitList_L(Ld);
	InitList_L(Le);
	InitList_L(Lf);
	
	Union(La,Lb,Lc);
	Inter(La,Lb,Ld);
	SubA(La,Lb,Le);
	SubB(La,Lb,Lf);

	printf("\n************* Result ****************\n");
	printf("A = {");
	ListTraverse_L(La);
	printf("}\n"); 

	printf("B = {");
	ListTraverse_L(Lb);
	printf("}\n"); 

	printf("A U B = {");
	ListTraverse_L(Lc);
	printf("}\n"); 

	printf("A ∩ B = {");
	ListTraverse_L(Ld);
	printf("}\n"); 

	printf("A - B = {");
	ListTraverse_L(Le);
	printf("}\n"); 	

	printf("B - A = {");
	ListTraverse_L(Lf);
	printf("}\n"); 	

	printf("*************************************\n");

	DestroyList_L(La);
	DestroyList_L(Lb);
	DestroyList_L(Lc);
	DestroyList_L(Ld);
	DestroyList_L(Le);
	DestroyList_L(Lf);

	getchar();
	getchar();
}