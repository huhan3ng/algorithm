/*
ID: huhan3n1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 200
#define MAX_K 100
int N,K;
unsigned int A[MAX_K][MAX_N]={0};	//横轴高度，纵轴个数

void scan(int a, int b){	//个数为 a,b 高度为 i,j
	for(int i=1;i<(MAX_K-1);i++){
		for(int j=1;j<(MAX_K-1);j++){
			//cout<<"K: "<<max(i,j)+1<<"N: "<<A[max(i,j)+1][a+b+1]<<endl;
			if(A[i][a]!=0 && A[j][b]!=0){
				A[max(i,j)+1][a+b+1]=(A[max(i,j)+1][a+b+1]+(A[i][a]*A[j][b]))%9901;
			}
		}
	}
}

int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
	A[1][1]=1;
	fin>>N>>K;
	for(int i=3;i<=N;i+=2){
		for(int j=1;j<=(i-2);j+=2){
			scan(j, i-j-1);
		}
	}
	fout<<A[K][N]<<endl;
    return 0;
}