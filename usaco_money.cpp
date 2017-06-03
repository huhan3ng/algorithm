/*
ID: huhan3n1
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int A[28]={0};
unsigned long long B[10001][28]={0};
int V,N;

unsigned long long calc(int iv, int in){
	unsigned long long ret=0;
	int i;
	for(i=in;i>=0;i-=A[iv]){
		ret+=B[i][iv-1];
	}
	return ret;
}

int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");
	fin>>V>>N;
	for(int i=1;i<=V;i++){
		fin>>A[i];
	}
	for(int i=1;i<=N;i++){
		B[i][0] = 0;	//所有值用1表示都是1中
	}
	B[0][0] = 1;
	for(int i=1;i<=V;i++){
		for(int j=0;j<=N;j++){
			B[j][i] = calc(i, j);
			//cout<<i<<" "<<j<<" "<<B[j][i]<<endl;
		}
	}
	fout<<B[N][V]<<endl;
    return 0;
}