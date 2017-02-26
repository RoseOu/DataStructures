#include "Prim_function.h"
using namespace std;

int main()
{
	MGraph G,g;
	CreateGraph(G);

	Prim(G,g);//g is the smallest tree for G
	PrintGraph(g);

	system("pause");
	return 0;
}
