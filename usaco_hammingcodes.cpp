/*
ID: huhan3n1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define min(a, b) ((a)<(b)?(a):(b))
int N,B,D;	//集合大小，位数，海明码距
char r[256];	//已访问

int distance(char x1, char x2){
	char x=x1^x2;
	int ret=0;
	while(x){
		x=x&(x-1);
		ret++;
	}
	return ret;
}

int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
	fin>>N>>B>>D;
	bool flag;
	for(int i=0,j=0;i<N && j<(1<<B);j++){
		flag = true;
		for(int k=0;k<i;k++){
			if(distance(r[k], j)<D){
				flag = false;
				break;
			}
		}
		if(flag){
			if(i>0 && i%10==0){
				fout<<endl;
			}
			fout<<j;
			if((i+1)%10!=0 && i!=(N-1)){
				fout<<" ";
			}
			r[i++] = j;
		}
	}
	fout<<endl;
	return 0;
}