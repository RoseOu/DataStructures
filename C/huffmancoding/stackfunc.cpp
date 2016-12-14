#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char ElemType;

typedef struct {
	ElemType *elem;
	int top;
	int stacksize;
	int incrementsize;
} SqStack;

void InitStack_Sq(SqStack &S){
	S.elem=new ElemType[STACK_INIT_SIZE];

	S.top=-1;
	S.stacksize=STACK_INIT_SIZE;
	S.incrementsize=STACKINCREMENT;
}

int StackLength_Sq(SqStack S){
	return S.top+1;
}

void incrementStack(SqStack &S)     //用于扩容的函数，扩大incrementsize个元素空间
{
	int i;
	ElemType *a;
	a=new ElemType[S.stacksize+S.incrementsize];
	for (i=0;i<StackLength_Sq(S);i++)
		a[i]=S.elem[i];
	delete[] S.elem;
	S.elem=a;
	S.stacksize += S.incrementsize;
}

void Push_Sq(SqStack &S,ElemType e){
	if(S.top==S.stacksize-1)
		incrementStack(S);
	S.elem[++S.top]=e;
}

bool Pop_Sq(SqStack &S,ElemType &e){
	if(S.top==-1)
		return false;
	e=S.elem[S.top--];
	return true;
}

void DetroyStack_Sq(SqStack &S) 
{
    delete S.elem; 
    S.top = -1;
    S.stacksize = 0;
    S.incrementsize = 0; 
}

void StackCopytoArray(SqStack S,char *array){
	int i;
	for(i=0;i<StackLength_Sq(S);i++){
		array[i]=S.elem[i];
	}
	array[i]='\0';
}

