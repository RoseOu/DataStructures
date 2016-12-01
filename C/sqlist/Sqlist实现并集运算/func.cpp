#include <iostream>
using namespace std;

const int LIST_INIT_SIZE=100;
const int LISTINCREMENT=10;

typedef int ElemType;    //定义元素类型
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
	int incrementsize;
} SqList;

void InitList_Sq(SqList &L)   //构造一个最大容量为maxsize的顺序表L
{
	L.elem=new ElemType[LIST_INIT_SIZE];     //为顺序表分配一个最大容量为maxsize的数组空间

	L.length=0;                       //顺序表中当前所含的元素个数为0
	L.listsize=LIST_INIT_SIZE;               //该顺序表可以容纳maxsize个数据元素
	L.incrementsize=LISTINCREMENT;        //需要时可以扩容incresize个元素空间

}

void DestroyList_Sq(SqList &L)       //释放顺序表L所占的存储空间
{
	delete[] L.elem;
	L.listsize=0;
	L.length=0;
}

void ClearList_Sq(SqList &L)        //清空顺序表
{
	L.elem=NULL;                   //把原本指向一个存储数据元素的数组的指针设为空指针
	L.length=0;                    //顺序表中元素个数设为0
}

bool ListEmpty_Sq(SqList L)        //判断顺序表是否为空表
{
	if (L.length==0)               //如果顺序表长度为0即为空表
		return true;
	else
		return false;
}

int ListLength_Sq(SqList L)         //返回顺序表的长度
{
	return L.length;
}

ElemType GetElem_Sq(SqList L,int i,ElemType &e)     //用e返回第i个元素的值
{
	e=L.elem[i-1];
	return e;
}

int LocateElem_Sq(SqList L,ElemType e)         //返回第一个其值与e相等的元素的位序
{
    int i;
    ElemType *p;
	i=1;                   //i的初值为第1个元素的位序
	p=L.elem;              //p的初值为第1个元素的存储位置
	while (i <= L.length && *p++ != e)     //从第1个元素开始依次判定
		++i;
	if (i<=L.length)    //如果在表中找到满足判定的元素为第i个元素
		return i;
	else
		return 0;
}

ElemType PriorElem_Sq(SqList L,ElemType cur_e,ElemType &pre_e)   //若cur_e不是第1个元素，则返回它的前驱
{
    int i;
    ElemType *p;
	i=1;             //i的初值为第1个元素的位序
	p=L.elem;        //p的初值为第1个元素的存储位置
	while (i <= L.length && *p++ != cur_e)    //从第1个元素开始依次判定
		++i;
	if ( i<= L.length && cur_e != L.elem[0])   //如果在表中找到满足判定的元素cur_e为第i个元素并且cur_e不是第一个元素
		pre_e=L.elem[i-2];                    //返回它的前驱
	return pre_e;
}

ElemType NextElem_Sq(SqList L,ElemType cur_e,ElemType &next_e)
{
    int i;
    ElemType *p;
	i=1;             //i的初值为第1个元素的位序
	p=L.elem;        //p的初值为第1个元素的存储位置
	while (i <= L.length && *p++ != cur_e)     //从第1个元素开始依次判定
		++i;
	if (i < L.length)  //如果在表中找到满足判定的元素cur_e为第i个元素并且cur_e不是最后一个元素
		next_e=L.elem[i];   //返后继的前驱
	return next_e;
}

void ListInsert_Sq(SqList &L,int i,ElemType e)     //在L的第i个元素之前插入新的元素e
{
	int j;
    ElemType *a,*p,*q;
	if (i<1 || i>L.length+1)        //若输入的i值不合法，返回错误信息
		cout << "Invalid i" << endl;
	if (L.length >= L.listsize)   //若当前存储空间已满，用increment函数扩容
	{
		a=new ElemType[L.listsize+L.incrementsize];
		for (j=0;j<L.length;j++)
			a[j]=L.elem[j];
		delete[] L.elem;
		L.elem=a;
		L.listsize += L.incrementsize;
	}
	q=&(L.elem[i-1]);             //q为插入位置
	for (p=&(L.elem[L.length-1]);p>=q;--p)   //插入位置以及之后的元素右移
		*(p+1) = *p;
	*q=e;          //在位置q中放入e
	++L.length;      //表长加1

}

void ListDelete_Sq(SqList &L,int i,ElemType &e)    //删除第i个元素
{
    ElemType *p,*q;
	if ((i<1) || (i>L.length))
		cout << "Invalid i" << endl;
	p=&(L.elem[i-1]);            //p为被删除元素的位置
	e=*p;                        //被删除元素的值赋给e
	q=L.elem+L.length-1;         //q为表尾元素的位置
	for (++p;p<=q;++p)           //被删除元素之后的元素左移
		*(p-1)=*p;               //表长减1
	--L.length;
}

void ListTraverse_Sq(SqList L)   //依次输出L中的每一个元素
{
	int i;
	for (i=0;i<L.length;i++)
		cout << L.elem[i] << ",";   //用“，”分隔每一个元素
}
