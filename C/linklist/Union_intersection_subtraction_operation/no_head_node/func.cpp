#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

void InitList_L(LinkList &L)    //构造一个空的链表
{
	L=NULL;         //定义一个头指针
}

void DestroyList_L(LinkList &L)   //销毁一个链表
{
	LNode *p;
	while(L!=NULL)    //逐个删除节点
	{
		p=L;
		L=p->next;
		delete p;
	}
	delete L;     //删除头指针
}

void ClearList_L(LinkList &L)  //清空链表
{
	L=NULL;
}

bool ListEmpty_L(LinkList L)  //判断链表是否为空
{
	if (L==NULL)
		return true;
	else
		return false;
}

int ListLength_L(LinkList L)   //返回链表的长度
{
	int k=0;
	LNode *p=L;
	while(p)
	{
		p=p->next;
		k=k+1;
	}
	return k;
}

void GetElem_L(LinkList L,LNode *q,ElemType &e)  //用e返回链表中的位置为q的数据元素的值
{
	e=q->data;
}

LNode* LocateElem_L(LinkList L, ElemType e)  //返回第一个其值与e相等的数据元素在链表中的位置（即指向该数据元素所在结点的指针）
{
	LNode *p=L;
	while(p && p->data!=e)
	{
		p=p->next;
	}
	return p;
}

void PriorElem_L(LinkList L,ElemType cur_e, ElemType &pre_e)  //若cur_e是L的元素但不是第一个，则用pre_e返回它的前驱的数据域
{
	LNode *p=L;   //一开始p指向第一个结点
	LNode *q=p->next;  //q指向q所指向的结点的下一个结点
	while(q->data!=cur_e)
	{
		p=p->next;
		q=q->next;
	}
	pre_e=p->data;
}
 
void NextElem_L(LinkList L,ElemType cur_e,ElemType &next_e)   //若cur_e是L的元素但不是最后一个，则用next_e返回它的后继的数据域
{
	LNode *p=L;  //若p指向第一个结点
	while(p->data!=cur_e)
	{
		p=p->next;
	}
	next_e=p->next->data;
}

void ListInsert_L(LinkList &L,LNode *p,LNode *e)    //指针p指向L为头指针的链表中的某个结点，将e结点插入到p结点之前
{
	LNode *q;
	if (p==L)    //若p指向第一个结点
	{
		e->next=L;
		L=e;
	}
	else
	{
		q=L;
		while(q->next!=p)
		{
			q=q->next;
			q->next=e;
			e->next=p;
		}
	}
}

void ListDelete_L(LinkList &L,LNode *p,ElemType &e)   //指针p指向L为头指针的链表中的某个结点，从链表中删除该结点并由e返回该结点的数据域
{
	LNode *q=L;
	if (p==L)  //若p指向第一个结点
	{
		L=p->next;
	}
	else
	{
		while(q->next!=p)
		{
			q=q->next;
			q->next=p->next;
		}
	}
	e=p->data;
	delete p;
}

void ListTraverse_L(LinkList L)  //依次输出链表中结点的数据域
{
	while(L != NULL)
	{
		cout << L->data << ",";
		L=L->next;
	}
}
