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
int C[102][102]={0};	//存放属于第几层母公司,有约束：一个公司只被一个公司control（除自己）
int D[102][102]={0};
void addPct(int cur, int child, int p);
void addCct(int cur, int child, int p);
void addRela(int i, int j, int p, int type);
int E[5000][3]={0};
int f;

void addPct(int cur, int child, int p){	//父公司统统间接增持
	for(int i=0;i<=100;i++){
		if(C[i][cur]==1){ //i control cur
				//cout<<"addPct   "<<cur<<"   "<<child<<"   "<<p<<endl;
				addRela(i, child, p, 0);
			break;
		}
	}
}

void addCct(int cur, int child, int p){	//添加当前公司对控制的子公司的子公司的控股影响
	for(int i=0;i<=100;i++){
		if(A[child][i]){	//child has i => cur has i
			//cout<<"addCct   "<<cur<<"   "<<child<<"   "<<p<<endl;
			addRela(cur, i, D[child][i], 1);
		}
	}
}

void addRela(int i, int j, int p, int type){	//type=0 直接控股 1 间接控股
	if(i==j){
		return;
	}
	//cout<<"addRela   "<<i<<"   "<<j<<"   "<<p<<endl;
	A[i][j]+=p;	//直接导致i 对 j 控制增加
	if((A[i][j]-p)<THREHOLD && A[i][j]>=THREHOLD){	//控制关系建立，间接导致 i 对 j直接持股子公司的增持
		//cout<<"controls   "<<i<<"   "<<j<<"   "<<A[i][j]<<endl;
		C[i][j]=++B[j];
		addCct(i, j, p);
	}
	if(type==0)	//当i对j直接增持，才会导致i的父公司对j增持
		addPct(i, j, p);
}

int main() {
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
	fin>>n;
	for(int k=0;k<n;k++){
		fin>>i>>j>>p;
		D[i][j]+=p;	//直接持股
		E[f][0]=i;
		E[f][1]=j;
		E[f][2]=p;
		f++;
		//cout<<"addDirect   "<<i<<"   "<<j<<"   "<<p<<endl;
	}
	
	for(int k=0;k<f;k++){
		addRela(E[k][0], E[k][1], E[k][2], 0);
	}
	
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			if(A[i][j]>=THREHOLD){
				fout<<i<<" "<<j<<endl;
			}
		}
	}
    return 0;
}