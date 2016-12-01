//杨辉三角的实现

#include <iostream>
using namespace std;

const QUEUE_INIT_SIZE=100;
const QUEUEINCREMENT=100;

typedef int ElemType;

typedef struct{
	ElemType *elem;
	int front;
	int rear;
	int queuesize;
	int incrementsize;
} SqQueue;

void InitQueue_Sq(SqQueue &Q,int maxsize=QUEUE_INIT_SIZE,int incresize=QUEUEINCREMENT){
	Q.elem=new ElemType[maxsize+1];
	Q.queuesize=maxsize;
	Q.incrementsize=incresize;
	Q.front=Q.rear=0;
}

bool DeQueue_Sq(SqQueue &Q,ElemType &e){
	if(Q.front==Q.rear)return false;
	e=Q.elem[Q.front];
	Q.front=(Q.front+1)%Q.queuesize;
	return true;
}

void incrementQueuesize(SqQueue &Q){
	ElemType *a;
	int k;
	a=new ElemType[Q.queuesize+Q.incrementsize];
	for(k=0;k<Q.queuesize-1;k++)
		a[k]=Q.elem[(Q.front+k)%Q.queuesize];
	delete [] Q.elem;
	Q.elem=a;
	Q.front=0;
	Q.rear=Q.queuesize-1;
	Q.queuesize+=Q.incrementsize;
}

void EnQueue_Sq(SqQueue &Q,ElemType e){
	if((Q.rear+1)%Q.queuesize==Q.front)
		incrementQueuesize(Q);
	Q.elem[Q.rear]=e;
	Q.rear=(Q.rear+1)%Q.queuesize;
}


bool QueueEmpty(SqQueue Q){
	if(Q.front==Q.rear)
		return false;
	else
		return true;
}

void GetHead_Sq(SqQueue Q,ElemType &e){
	e=Q.elem[Q.front];
}


void Yanghui(int n){
	int i,k;
	ElemType s,e;
	SqQueue Q;
	for(i=1;i<=n;i++)
		cout << ' ';
	cout << '1' << endl;
	InitQueue_Sq(Q,n+2);
	EnQueue_Sq(Q,0);
	EnQueue_Sq(Q,1);
	EnQueue_Sq(Q,1);
	k=1;
	while(k<n){
		for(i=1;i<=n-k;i++)
			cout<<' ';
		EnQueue_Sq(Q,0);
		do{
			DeQueue_Sq(Q,s);
			GetHead_Sq(Q,e);
			if(e)
				cout<<e<<' ';
			else
				cout<<endl;
			EnQueue_Sq(Q,s+e);
		}while(e!=0);
		k++;
	}
	DeQueue_Sq(Q,e);
	while(!QueueEmpty(Q)){
		DeQueue_Sq(Q,e);
		cout<<e<<' ';
	}
}

void main(){
	Yanghui(10);
	getchar();
}