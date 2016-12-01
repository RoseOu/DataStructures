#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

void InitList_L(LinkList &L)    //����һ���յ�����
{
	L=NULL;         //����һ��ͷָ��
}

void DestroyList_L(LinkList &L)   //����һ������
{
	LNode *p;
	while(L!=NULL)    //���ɾ���ڵ�
	{
		p=L;
		L=p->next;
		delete p;
	}
	delete L;     //ɾ��ͷָ��
}

void ClearList_L(LinkList &L)  //�������
{
	L=NULL;
}

bool ListEmpty_L(LinkList L)  //�ж������Ƿ�Ϊ��
{
	if (L==NULL)
		return true;
	else
		return false;
}

int ListLength_L(LinkList L)   //��������ĳ���
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

void GetElem_L(LinkList L,LNode *q,ElemType &e)  //��e���������е�λ��Ϊq������Ԫ�ص�ֵ
{
	e=q->data;
}

LNode* LocateElem_L(LinkList L, ElemType e)  //���ص�һ����ֵ��e��ȵ�����Ԫ���������е�λ�ã���ָ�������Ԫ�����ڽ���ָ�룩
{
	LNode *p=L;
	while(p && p->data!=e)
	{
		p=p->next;
	}
	return p;
}

void PriorElem_L(LinkList L,ElemType cur_e, ElemType &pre_e)  //��cur_e��L��Ԫ�ص����ǵ�һ��������pre_e��������ǰ����������
{
	LNode *p=L;   //һ��ʼpָ���һ�����
	LNode *q=p->next;  //qָ��q��ָ��Ľ�����һ�����
	while(q->data!=cur_e)
	{
		p=p->next;
		q=q->next;
	}
	pre_e=p->data;
}
 
void NextElem_L(LinkList L,ElemType cur_e,ElemType &next_e)   //��cur_e��L��Ԫ�ص��������һ��������next_e�������ĺ�̵�������
{
	LNode *p=L;  //��pָ���һ�����
	while(p->data!=cur_e)
	{
		p=p->next;
	}
	next_e=p->next->data;
}

void ListInsert_L(LinkList &L,LNode *p,LNode *e)    //ָ��pָ��LΪͷָ��������е�ĳ����㣬��e�����뵽p���֮ǰ
{
	LNode *q;
	if (p==L)    //��pָ���һ�����
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

void ListDelete_L(LinkList &L,LNode *p,ElemType &e)   //ָ��pָ��LΪͷָ��������е�ĳ����㣬��������ɾ���ý�㲢��e���ظý���������
{
	LNode *q=L;
	if (p==L)  //��pָ���һ�����
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

void ListTraverse_L(LinkList L)  //������������н���������
{
	while(L != NULL)
	{
		cout << L->data << ",";
		L=L->next;
	}
}
