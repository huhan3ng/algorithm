/*
ID: huhan3n1
PROG: concom
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int n,i,j,p;
int A[102][102]={0};
int THREHOLD=50;
int B[102]={0};	//公司的父亲个数
int C[102][102]={0};
void addPct(int cur, int child, int p);
void addCct(int cur, int child, int p);
void addRela(int i, int j, int p);

void addPct(int cur, int child, int p){	//添加当前公司母公司对子公司的控股影响
	for(int i=0;i<100;i++){
		if(C[i][cur]==1){ //i control cur
			addRela(i, child, p);
			break;
		}
	}
}

void addCct(int cur, int child, int p){	//添加当前公司对控制的子公司的子公司的控股影响
	for(int i=0;i<100;i++){
		if(A[child][i]){	//child has i => cur has i
			addRela(cur, i, A[child][i]);
		}
	}
}

void addRela(int i, int j, int p){
	cout<<"addRela   "<<i<<"   "<<j<<"   "<<p<<endl;
	if(i==j){
		return;
	}
	A[i][j]+=p;	//直接导致i 对 j 控制增加
	if((A[i][j]-p)<THREHOLD && A[i][j]>=THREHOLD){	//控制关系建立，间接导致 i 对 j的子公司的持股变化
		C[i][j]=++B[j];
		addCct(i, j, p);
	}
	//直接导致所有a的父公司对j的持股变化
	addPct(i, j, p);
}

int main() {
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
	fin>>n;
	for(int k=0;k<n;k++){
		fin>>i>>j>>p;
		addRela(i, j, p);
	}
	
    return 0;
}