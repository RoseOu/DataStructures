#include <iostream>
using namespace std;

const int Infinity=10000;
const int max_vertex_num=6;
const int incresize=5;
typedef int VRType;
typedef int InfoType;
typedef int VertexType;

typedef struct ArcCell
{
	VRType adj;  //VRType是顶点关系类型，对无权图，用1或0表示；对带权图，即为权值类型
}ArcCell,AdjMatrix[max_vertex_num][max_vertex_num];
 
typedef struct
{
	VertexType vexs[max_vertex_num];//顶点数组
	AdjMatrix arcs;//邻接矩阵，存放每条弧的权重
	int vexnum;//顶点数
	int arcnum;//弧数
}MGraph;

typedef struct
{
	int adjvex;//在图中节点的下标
	VRType lowcost;//到adjvex的弧的最小权重
}closedge;

void CreateGraph(MGraph &G)
{
	int i=0,j=0;

	//
	cout<<"please input the name of each vertex in order : ";
	for (;i<max_vertex_num;i++)
		cin>>G.vexs[i];
	G.vexnum=max_vertex_num;

	//
	cout<<"please input the values between each vertex in order : \n"
		<<"(\"-1\" means there is no arc between the two vertexs ) \n";
	for (i=0,G.arcnum=0;i<max_vertex_num;i++)
	{
		cout<<"arcs between \""<<G.vexs[i]<<"\" and other vertexs : \n";
		for (j=0;j<max_vertex_num;j++)
		{
			if (j==i)
				G.arcs[i][j].adj=0;
			else
			{
				cout<<G.vexs[j]<<": ";
				cin>>G.arcs[i][j].adj;
				if (G.arcs[i][j].adj==-1)
					G.arcs[i][j].adj=Infinity;
				else
				G.arcnum++;
			}
		}//for
	}//for
}

int minedge(closedge* edge)
{//返回最小权值所在节点的下标
	int min=0,i=0;

	while (edge[min].lowcost==0)
		min++;

	for (i=0;i<max_vertex_num;i++)
	{
		if (edge[min].lowcost>edge[i].lowcost&&edge[i].lowcost!=0)
			min=i;
	}
	return min;
}

void Prim(MGraph G,MGraph &g)
{	
	//g is the smallest tree for G
	int i=0,j=0;
	
	//init g
	for (;i<G.vexnum;i++)
		g.vexs[i]=G.vexs[i];
	
	g.vexnum=G.vexnum;
	
	for (i=0;i<max_vertex_num;i++)
	{
		for(j=0;j<max_vertex_num;j++)
		{
			if (j==i)
				g.arcs[i][j].adj=0;
			else
				g.arcs[i][j].adj=Infinity;
		}
	}
	g.arcnum=0;

	//初始化edge[]
	//先将edge[].adjvex的初值置为图中第一个元素
	//将edge[].lowcost的初值置为途中第一个元素到各个顶点的弧的权重
	closedge edge[max_vertex_num];
	for(i=0;i<max_vertex_num;i++)
	{
		edge[i].adjvex=0;
		edge[i].lowcost=G.arcs[0][i].adj;
	}

	int subscript[max_vertex_num],closelem=Infinity;
	for(i=0;i<max_vertex_num;i++)
		subscript[i]=-1;
	//subscript存储已经归并到最小生成树的节点在邻接矩阵中的下标
	//closelem作为中间存储当前权重最小的边对应的节点下标
	subscript[0]=0;

	for(i=1;i<max_vertex_num;i++)
	{
		//将closedge edge[]中的节点全部赋为到已归并集合的最短路径的过程
		for(j=0;j<max_vertex_num;j++)
		{
			if(edge[j].lowcost>G.arcs[j][subscript[i-1]].adj)
			{//若此时该节点到已归并部分的权重有更小的值
				edge[j].adjvex=subscript[i-1];//
				edge[j].lowcost=G.arcs[j][subscript[i-1]].adj;
			}//if
		}//for

		//将最小权重弧输入到g中的过程
		closelem=minedge(edge);
		//邻接矩阵是对称的
		g.arcs[edge[closelem].adjvex][closelem].adj=edge[closelem].lowcost;
		//将closedge edge[]中的最小权重赋给g的对应位置
		subscript[i]=closelem;
		//将最小权重所连接的节点下标归并到一个集合中
	}//for
}


void PrintGraph(MGraph g)
{
	int i=0,j=0;
	for (i=0;i<max_vertex_num;i++)
	{
		cout<<i+1<<" | ";
		for(j=0;j<max_vertex_num;j++)
		{
			if (g.arcs[i][j].adj==Infinity)
				cout<<"∞ ";
			else
				cout<<g.arcs[i][j].adj<<" ";
		}
		cout<<" | "<<endl;
	}
}

