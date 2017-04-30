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

void heapify(int i, vector<int> &a){	//取最大的置换到父节点的位置
	if(rightChild(i)<a.size()){	//左右子节点都有
		if(a[rightChild(i)]>=a[leftChild(i)] && a[rightChild(i)]>=a[i]){
			swap(i, rightChild(i), a);
			heapify(rightChild(i), a);
		}
		if(a[leftChild(i)]>=a[rightChild(i)] && a[leftChild(i)]>=a[i]){
			swap(i, leftChild(i), a);
			heapify(leftChild(i), a);
		}
	} else if(leftChild(i)<a.size()){//只有左子节点
		if(a[leftChild(i)]>=a[i]){
			swap(i, leftChild(i), a);
			heapify(leftChild(i), a);
		}
	}
}

void buildMaxheap(vector<int> &heap){
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
	while(parent(i)<v.size() && parent(i)>=0 && v[parent(i)]<v[i]){
		swap(i, parent(i), v);
		i=parent(i);
	}
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
			vector<int> a = vector<int>(3,0);
	a[0]=1;
	a[1]=3;
	a[2]=2;
	buildMaxheap(a);
	heap_insert(4, a);
	heap_insert(5, a);
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<endl;
	}
	cout<<heap_pop(a)<<endl;
	cout<<heap_pop(a)<<endl;
	cout<<heap_pop(a)<<endl;
	cout<<heap_pop(a)<<endl;
	cout<<heap_pop(a)<<endl;
	
	
    return 0;
}
