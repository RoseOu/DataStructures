#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 100

typedef struct{
	int xpos;  
	int ypos;
} PosType;

typedef PosType ElemType;

typedef struct DQNode{
	PosType seat;
	struct DQNode *next;
	struct DQNode *pre;
} DQNode, *DQueuePtr;

typedef struct{
	DQueuePtr front;
	DQueuePtr rear;
} DLinkQueue;

typedef struct{
	ElemType *elem;
	int top;
}SqStack;

void InitStack_Sq(SqStack &S)
{
	S.elem=new ElemType[STACK_INIT_SIZE];
	S.top=-1;
}
void Push_Sq(SqStack &S,ElemType e)
{
	S.elem[++S.top]=e;
}

void InitQueue(DLinkQueue &Q){
	Q.front=NULL;
	Q.rear=NULL;
}

void EnQueue(DLinkQueue &Q,PosType e){
	DQueuePtr p=new DQNode;
	p->seat.xpos=e.xpos;
	p->seat.ypos=e.ypos;
	p->next=NULL;
	if(!Q.rear){
		p->pre=NULL;
		Q.rear=p;
		Q.front=p;
	}
	else{
		p->pre=Q.front;
		Q.rear->next=p;
		Q.rear=p;
	}
}

void GetHead(DLinkQueue Q,PosType &e){
	e.xpos=Q.front->seat.xpos;
	e.ypos=Q.front->seat.ypos;
}

void DeQueue(DLinkQueue &Q){
	Q.front=Q.front->next;
}

bool QueueEmpty(DLinkQueue Q){
	return (Q.front==NULL);
}

bool Pass(PosType npos,int &m,int &n,int**maze,bool**visited){
	if(npos.xpos>=0 && npos.xpos<=m-1 &&
	   npos.ypos>=0 && npos.ypos<=n-1 &&
	   maze[npos.xpos][npos.ypos]==0 &&
	   visited[npos.xpos][npos.ypos]==false)
		return true;
	else
		return false;  
}

PosType NextPos(PosType p,int v){  //当前位置的八个方位
	PosType q;
	switch (v){
		case 0:{
			q.xpos=p.xpos;
			q.ypos=p.ypos+1;
		}break;
		case 1:{
			q.xpos=p.xpos+1;
			q.ypos=p.ypos+1;
		}break;
		case 2:{
			q.xpos=p.xpos+1;
			q.ypos=p.ypos;
		}break;
		case 3:{
			q.xpos=p.xpos+1;
			q.ypos=p.ypos-1;
		}break;
		case 4:{
			q.xpos=p.xpos;
			q.ypos=p.ypos-1;
		}break;
		case 5:{
			q.xpos=p.xpos-1;
			q.ypos=p.ypos-1;
		}break;
		case 6:{
			q.xpos=p.xpos-1;
			q.ypos=p.ypos;
		}break;
		case 7:{
			q.xpos=p.xpos-1;
			q.ypos=p.ypos+1;
		}break;
	}
	return q;
}

bool ShortestPath(int **maze,int m,int n,SqStack &S){
	int i,j,v;
	DLinkQueue Q;
	PosType curpos,e,npos;
	DQueuePtr p;
	bool **visited;
	bool found;
	visited=new bool*[m];
	for(i=0;i<m;i++)
		visited[i]=new bool[n];
	InitQueue(Q);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			visited[i][j]=false;
	if(maze[0][0]!=0)
		return false;
	e.xpos=0;
	e.ypos=0;
	EnQueue(Q,e);
	found=false;
	while(!found && !QueueEmpty(Q)){
		GetHead(Q,curpos);
		for(v=0;v<8 && !found;v++){
			npos=NextPos(curpos,v);
			if(Pass(npos,m,n,maze,visited)){
				EnQueue(Q,npos);
				visited[npos.xpos][npos.ypos]=true;
			}
			if(npos.xpos==m-1 && npos.ypos==n-1)
				found=true;
		}
		DeQueue(Q);
	}
	if(found){
		InitStack_Sq(S);
		p=Q.rear;
		while(p){
			Push_Sq(S,p->seat);
			p=p->pre;
		}
		return true;
	}
	else
		return false;
}

int main()
{
    int m,n,i,j;
    int** maze;
    SqStack S;

	cout<<"Input the numbers of cows:";
	cin>>m;
	cout<<"Input the number of rows:";
	cin>>n;

	maze=new int*[m];
	for(i=0;i<m;i++)
		maze[i]=new int[n];

	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			cout << "Input the number of " << "(" << i << "," << j << "):";
			cin>>maze[i][j];
		}

	ShortestPath(maze,m,n,S);

	cout << "The shortest path:" << endl;
	for(i=S.top;i>=0;i--)
        cout << "(" << S.elem[i].xpos << "," << S.elem[i].ypos << ")" << endl;
	return 0;
}
