/*
ID: huhan3n1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int w[3]={2,5,10};	//容量
int v[3]={0,0,10};	//实际存储量
int f[21][21][21]={0};
int r[21]={0};
void pour(int src, int dst){
	int d;
	if(src!=dst){
		if((v[src]+v[dst])<=w[dst]){
			d=v[src];
		} else {
			d=w[dst]-v[dst];
		}
		v[src]-=d;
		v[dst]+=d;
	}
}

void pourAndPour(){
	if(f[v[0]][v[1]][v[2]]){
		return;
	} else {
		f[v[0]][v[1]][v[2]]=1;
		//cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	}
	int v_b[3]={0};	//实际存储量	
	v_b[0]=v[0];
	v_b[1]=v[1];
	v_b[2]=v[2];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i!=j){
				pour(i, j);
				pourAndPour();
				v[0]=v_b[0];
				v[1]=v_b[1];
				v[2]=v_b[2];
			}
		}
	}
}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
	for(int i=0;i<3;i++){
		fin>>w[i];
	}
	v[2]=w[2];
	//cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	pourAndPour();
	for(int i=0;i<1;i++){
		for(int j=0;j<21;j++){
			for(int k=0;k<21;k++){
				if(f[i][j][k]){
					r[k]=1;
				}
			}
		}
	}
	vector<int> ret;
	for(int i=0;i<21;i++){
		if(r[i]){
			ret.push_back(i);
		}
	}
	for(int i=0;i<(ret.size()-1);i++){
		fout<<ret[i]<<" ";
	}
	if(ret.size()>0){
		fout<<ret[ret.size()-1];
	}
	fout<<endl;
}