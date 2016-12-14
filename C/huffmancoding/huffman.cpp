#include "stackfunc.cpp"

typedef struct {
    int weight;
    int lchild,rchild;
    int flag;
} HTNode;

typedef struct {
    HTNode *HTree;
    int root;
} HuffmanTree;

typedef char** HuffmanCode;

void Select(HTNode* HTree,int num,int &s1,int &s2){
	int i,j;
	int min1=999,min2=999;

	for(i=0;i<num;i++){
		if(HTree[i].weight<=min1 && HTree[i].flag == 0){
			min1=HTree[i].weight;
			s1=i;
		}
	}
	HTree[s1].flag=1;

	for(j=0;j<num;j++){
		if(HTree[j].weight<min2 && j!=s1 && HTree[j].flag == 0){
			min2=HTree[j].weight;
			s2=j;
		}
	}
	HTree[s2].flag=1;
}


void CreateHuffmanTree(HuffmanTree &HT,int w[],int n){
	int m,i,s1,s2;
	HTNode *p;

	if(n<=1)
		return;
	m=2*n-1;
	HT.HTree=new HTNode [m];
	for(p=HT.HTree,i=0;i<n;++i,++p,++w){
		p->lchild=-1;
		p->rchild=-1;
		p->weight=*w;
		p->flag=0;
	}
	for(;i<m;++i,++p){
		p->lchild=-1;
		p->rchild=-1;
		p->weight=0;
		p->flag=0;
	}
	for(i=n;i<m;++i){
		Select(HT.HTree,i,s1,s2);
		HT.HTree[i].lchild=s1;
		HT.HTree[i].rchild=s2;
		HT.HTree[i].weight=HT.HTree[s1].weight+HT.HTree[s2].weight;
	}
	HT.root=m-1;
}

void Coding(HuffmanTree HT,int i,SqStack &S,HuffmanCode &HC){
	ElemType e;

	if(HT.HTree){
		if((HT.HTree[i].lchild==-1)&&(HT.HTree[i].rchild==-1)){
			HC[i]=new char[StackLength_Sq(S)];
			StackCopytoArray(S,HC[i]);
		}
		else{
			Push_Sq(S,'0');
			Coding(HT,HT.HTree[i].lchild,S,HC);
			Pop_Sq(S,e);
			Push_Sq(S,'1');
			Coding(HT,HT.HTree[i].rchild,S,HC);
			Pop_Sq(S,e);
		}
	}
}

void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n){
	SqStack S;
	HC=new char * [n];
	InitStack_Sq(S);
	Coding(HT,HT.root,S,HC);
}

void OutputCode(HuffmanCode HC,int n){
	int i,j;
	cout << "The Huffman Code:" << endl;
	for (i=0;i<n;i++){
		for (j=0;HC[i][j]!='\0';j++){
			cout << HC[i][j];
		}
		cout << endl;
	}
}

void OutputHuffmanTree(HuffmanTree HT,int n){
	cout << "The Huffman Tree:" << endl;
	for(int i=0;i<2*n-1;i++){
		cout << HT.HTree[i].weight 
			 << " "
			 << HT.HTree[i].lchild 
			 << " "
			 << HT.HTree[i].rchild
			 << endl;
	}
}

int main(){
	int n,*w;
	HuffmanTree HT;
	HuffmanCode HC; 

	cout << "Input the numbers of values:";
	cin >> n;
	cout << "Please input the weight of each values." << endl;
	w=new int [n+1];
	for(int i=0;i<n;i++){
		cout << "Input the weight " << i+1 << ": ";
		cin >> w[i];
	}

	CreateHuffmanTree(HT,w,n);
	HuffmanCoding(HT,HC,n);

	OutputHuffmanTree(HT,n);
	OutputCode(HC,n);

	delete[] HT.HTree;

	return 0;
}
