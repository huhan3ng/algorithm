/*
ID: huhan3n1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define min(a,b) ((a)>(b)?(a):(b))
int n;
bool flag[200][200]={false};
int parent(int i){
	return (i+1)/2-1;
}

int leftChild(int i){
	return 2*(i+1)-1;
}

int rightChild(int i){
	return 2*(i+1);
}

void swap(int i, int j, vector<int> &a){
	//cout<<"i: "<<i<<"j: "<<j<<"ai"<<a[i]<<"aj"<<a[j]<<endl;
	a[i]+=a[j];
	a[j]=2*a[j]-a[i];
	a[i]=(a[i]+a[j])/2;
	a[j]=a[i]-a[j];
	//cout<<"------i: "<<i<<"j: "<<j<<"ai"<<a[i]<<"aj"<<a[j]<<endl;
}

bool heap_smaller(int v1, int v2){
	int p1=v1/1000;
	int q1=v1%1000;
	int p2=v2/1000;
	int q2=v2%1000;
	return (q1*p2<q2*p1);
}

void heapify(int i, vector<int> &a){	//取最大的置换到父节点的位置
	if(rightChild(i)<a.size()){	//左右子节点都有
		if(heap_smaller(a[rightChild(i)], a[leftChild(i)]) && heap_smaller(a[rightChild(i)] ,a[i])){
			swap(i, rightChild(i), a);
			heapify(rightChild(i), a);
		}
		if(heap_smaller(a[leftChild(i)], a[rightChild(i)]) && heap_smaller(a[leftChild(i)], a[i])){
			swap(i, leftChild(i), a);
			heapify(leftChild(i), a);
		}
	} else if(leftChild(i)<a.size()){//只有左子节点
		if(heap_smaller(a[leftChild(i)] ,a[i])){
			swap(i, leftChild(i), a);
			heapify(leftChild(i), a);
		}
	}
}

void buildMinheap(vector<int> &heap){
	if(heap.size()<=1){
		return;
	}
	for(int i=(heap.size()-1)/2;i>=0;i--){
		heapify(i, heap);
	}
}

int heap_pop(vector<int> &a){	//如果没有元素了就返回-1
	if(a.size()==0){
		return -1;
	}
	int ret=a[0];
	a[0]=a[a.size()-1];
	a.pop_back();
	heapify(0, a);
	return ret;
}



void heap_insert(int a, vector<int> &v){
	v.push_back(a);
	int i=v.size()-1;
	while(parent(i)<v.size() && parent(i)>=0 && heap_smaller(v[i], v[parent(i)])){
		swap(i, parent(i), v);
		i=parent(i);
	}
}

/**规约分数*/
void doReduce(int &p, int &q){
	int i=0;
	if(q==0){
		p=1;
		q=0;
		return;
	}
	for(i=2;i<=min(p,q);i++){
		if(p%i==0 && q%i==0){
			p/=i;
			q/=i;
			i=1;
		}
	}
	/**
	while(1){
		if(i>min(p,q)){
			return;
		}
		for(i=2;i<=min(p,q);i++){
			if(p%i==0 && q%i==0){
				p/=i;
				q/=i;
			}
		}
	}*/
}

void dumpHeap(vector<int> &a, ofstream &fout){
	int p,q,r;
	while(a.size()>0){
		r=heap_pop(a);
		p=r/1000;
		q=r%1000;	//分子增大或分母减小
		fout<<q<<"/"<<p<<endl;
		//cout<<q<<"/"<<p<<endl;
	}
}

bool exist(int p, int q){
	doReduce(p, q);
	return flag[p][q];
}

void mark(int p, int q){
	doReduce(p, q);
	flag[p][q]=true;
	return;
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
	vector<int> a;
	int v,w;//p分母 q分子
	fin>>n;
	//cout<<n<<endl;
	buildMinheap(a);
	//mark(n, 0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(!exist(i, j)){
				v=i;w=j;
				doReduce(v, w);
				mark(i, j);
				//cout<<"i "<<i<<"j "<<j<<endl;
				heap_insert(v*1000+w, a);
			}
		}
	}
	dumpHeap(a, fout);
    return 0;
}
