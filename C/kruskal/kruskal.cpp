#include <iostream>
using namespace std;

typedef struct{   
	int data;    //顶点信息
    int set;   
} VEX;

typedef struct {
    int vexs, vexe;  //边依附的两顶点
    int score;          //边的权值
    int flag;             //标志域
} EDGE;

void Init(VEX *vex,EDGE *edge,int vexnum,int edgenum){    //初始化顶点数组和边数组，令每个顶点的set互不相同,每个边的flag为0
    int i;
    for(i=0;i<vexnum;i++)
        vex[i].set=i+1;
    for(i=0;i<edgenum;i++)
        edge[i].flag=0;
}

void Kruskal(EDGE *edge,VEX *vex,int vexnum,int edgenum,EDGE *S){
    int i,min,k,j,w;
    k=0;
    int *relaedge;
	relaedge=new int [vexnum]; 

    while(k<vexnum-1){
        for(i=0;i<edgenum;i++){
            if(edge[i].flag==0)
             	min=i;
        }
        //选出权值最小且flag为0的边
        for(i=0;i<edgenum;i++){
            if(edge[i].score<edge[min].score && edge[i].flag==0)
                min=i;
        }
        //若该边依附的两个顶点的set值不同，即非连通，则令该边的flag=1, 选中该边；
        //再令该边依附的两顶点的集合以及两集合中所有顶点的set相同
        if (vex[(edge[min].vexs)-1].set!=vex[(edge[min].vexe)-1].set){
            edge[min].flag=1;
            S[k]=edge[min];
            
            w=vex[(edge[min].vexe)-1].set;
            vex[(edge[min].vexe)-1].set=vex[(edge[min].vexs)-1].set;

            for(i=0;i<vexnum;i++){
            	if(vex[i].set==w)
            		vex[i].set=vex[(edge[min].vexs)-1].set;
            }
			k++;
        }
        //若该边依附的两个顶点的set值相同，即连通，则令该边的flag=2, 即舍去该边
        else
            edge[min].flag=2;
    }
}

int main(){
    //用顶点数组和边数组存放顶点和边信息
    VEX *vex;
    EDGE *edge,*S;
    int vexnum,edgenum;

    cout<<"Input the numbers of vex: "; //输入顶点数
    cin>>vexnum;
    cout<<"Input the numbers of edge: "; //输入弧数
    cin>>edgenum;

    vex=new VEX [vexnum];
    cout<<"Input the number of vex:(for example: 1 2 3 4 5 6)"<<endl; //输入顶点的编号
    for(int j=0;j<vexnum;j++)
        cin>>vex[j].data;

    edge=new EDGE [edgenum];
    cout<<"Input each edge in this format 'vexs vexe score':(for example:1 2 3)"<<endl; //一次输入每一条弧的两个顶点和权重
    for(int k=0;k<edgenum;k++){
        cin>>edge[k].vexs>>edge[k].vexe>>edge[k].score;
    }

    S=new EDGE [edgenum];

    Init(vex,edge,vexnum,edgenum);
    Kruskal(edge,vex,vexnum,edgenum,S);

    cout<<"************"<<endl;
    cout<<"The choosen edge:"<<endl;

    for(int i=0;i<vexnum-1;i++){
    	cout<<"("<<S[i].vexs<<","<<S[i].vexe<<")"<<endl;
    }

    return 0;
}