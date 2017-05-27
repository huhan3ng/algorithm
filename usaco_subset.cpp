/*
ID: huhan3n1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

unsigned int v[1000]={0};
vector<int> w,u;
int s=0,t=0;

int sub(int a, int b){
	return a>b?a-b:b-a;
}

int add(int a, int b){
	return a+b;
}

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
	int n,t;
	fin>>n;
	v[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<681;j++){
			if(v[j]){	//存在差值为 j 的组合 v[j] 个
				w.push_back(j);
				u.push_back(v[j]);
				v[j]=0;
			}
		}
		while(w.size()>0){
			v[sub(w.back(),i)] += u.back();
			v[add(w.back(),i)] += u.back();
			//cout<<"添加 差值为"<<sub(w.back(),i)<<" "<< u.back()<<"个 "<<endl;
			//cout<<"添加 差值为"<<add(w.back(),i)<<" "<< u.back()<<"个 "<<endl;
			w.pop_back();
			u.pop_back();
		}
		//cout<<"---------------------------------------"<<endl;
	}
	fout<<v[0]<<endl;
	
    return 0;
}