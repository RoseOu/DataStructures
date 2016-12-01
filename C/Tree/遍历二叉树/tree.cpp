#include <iostream>
using namespace std;

typedef char TElemType;
const int MAXNUM=100;

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

//初始化二叉树
void InitBiTree(BiTree &T){
    char ch;
	cin >> ch;
	if (ch=='#')
		T=NULL;
	else{
		T=new BiTNode;
		T->data=ch;
		InitBiTree(T->lchild);
		InitBiTree(T->rchild);
	}
}

//销毁二叉树
void DestoryBiTree(BiTree &T){
    T=NULL;
}

//访问结点
void visit(BiTree T){
    cout << T->data;
}

//先序遍历
void Preorder(BiTree T,void(*visit)(BiTree)){
	if(T){
		visit(T);
		Preorder(T->lchild,visit);
		Preorder(T->rchild,visit);
	}
}

//中序遍历
void Midorder(BiTree T,void(*visit)(BiTree)){
    if(T){
        Midorder(T->lchild,visit);
        visit(T);
        Midorder(T->rchild,visit);
    }
}

//后序遍历
void Reorder(BiTree T,void(*visit)(BiTree)){
    if(T){
        Reorder(T->lchild,visit);
        Reorder(T->rchild,visit);
        visit(T);
    }
}

//层次遍历
void Levorder(BiTree T){
    BiTNode *p;
    BiTNode *q[MAXNUM];
    int front,rear;
    front=rear=-1;
    rear++;
    q[rear]=T;
    while(front!=rear){
        front=front+1;
        p=q[front];
        visit(p);
        if(p->lchild!=NULL){
            rear=rear+1;
            q[rear]=p->lchild;
        }
        if(p->rchild!=NULL){
            rear=rear+1;
            q[rear]=p->rchild;
        }
    }
}

int main(){
    BiTree T;
    cout << "输入字符序列:" << endl;
    InitBiTree(T);
    cout << "中序遍历:";
    Midorder(T,visit);
    cout << endl;
    cout << "后序遍历:";
    Reorder(T,visit);
    cout << endl;
    cout << "层次遍历:";
    Levorder(T);
    cout << endl;
    DestoryBiTree(T);
    return 0;
}
