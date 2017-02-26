#include <iostream>
using namespace std;

typedef int SElemType
const STACK_INIT_SIZE=100;
const STACKINCREMENT=10;

typedef struct{
    SElemType *elem;
    int top;
    int stacksize;
    int incrementsize;
} SqStack;

void InitStack_Sq(SqStack &s){
    S.elem=new SElemType[STACK_INIT_SIZE];
    S.top=-1;
    S.stacksize=STACK_INIT_SIZE;
    S.incrementsize=STACKINCREMENT;
}

bool GetTop_Sq(SqStack S,SElemType &e){
    if (S.top==-1)
        return false;
    e=S.elem[S.top];
    return true;
}

void Push_Sq(SqStack &s,SElemType e){
    if(S.top==S.stacksize-1)
        incrementStacksize(S);
    S.elem[++S.top]=e;
}

bool Pop_Sq(SqStack &s,SElemType &e){
    if(S.top==-1)
        return false;
    e=S.elem[S.top--];
    return true;
}