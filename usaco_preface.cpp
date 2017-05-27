/*
ID: huhan3n1
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int A[10][3]={
	{0,0,0},
	{0,0,1},
	{0,0,2},
	{0,0,3},
	{1,1,0},
	{0,1,0},
	{0,1,1},
	{0,1,2},
	{0,1,3},
	{0,1,4}
	};

int B[8]={0};	//I,V,X,L,C,D,M,?
char D[7]={'I','V','X','L','C','D','M'};
int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
	int n,t;
	fin>>n;
	for(int l=1;l<=n;l++){
		t=l;
		for(int k=1000,i=3,j=0;k>0;k/=10,i--){
			j=t/k;
			t%=k;
			if(j!=9){
				B[2*i]+=A[j][0]+A[j][2];
				B[2*i+1]+=A[j][1];
			} else {
				B[2*i]++;
				B[2*(i+1)]++;
			}
		}
	}
	for(int i=0;i<7;i++){
		if(B[i]){
			fout<<D[i]<<" "<<B[i]<<endl;
		}
	}
	
    return 0;
}