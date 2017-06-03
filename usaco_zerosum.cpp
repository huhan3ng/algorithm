/*
ID: huhan3n1
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int N=5;
char A[20]={1,' ',2,'+',3,'-',4,'-',5};
int offset;
int getNum(int i){	//取完设置offset为下一个符号位置
	int val=A[i];
	while(A[i+1]==' '){
		val=val*10+A[i+2];
		i+=2;
	}
	offset=i+1;
	return val;
}

void dumpA(ofstream& fout){
	for(int j=0;j<2*N-1;j++){
		if(j%2==0){
			fout<<(int)A[j];
		} else {
			fout<<A[j];
		}
	}
	fout<<endl;
}

void calcA(ofstream& fout){
	int i=1,left=0,right=0;
	while(i<2*N-1){
		if(i==1){
			left=getNum(0);
			offset += 1;
		} else {
			offset = i+1;
		}
		i=offset-1;
		right = getNum(offset);
		if(A[i]=='+'){
			left+=right;
			//cout<<"left "<<left<<endl;
		} else {
			//cout<<"a[i] "<<A[i]<<endl;
			left-=right;
		}
		i=offset;
	}
	if(left==0){
		dumpA(fout);
	}
}

void scan(int i, int l, ofstream& fout){
	if(l==0){
		A[2*i-2]=i;
		//dumpA();
		calcA(fout);
	} else {
		A[2*i-2]=i;
		A[2*i-1]=' ';
		scan(i+1, l-1, fout);
		A[2*i-1]='+';
		scan(i+1, l-1, fout);
		A[2*i-1]='-';
		scan(i+1, l-1, fout);
	}
}

int main() {
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");
	//calcA(fout);return 0;
	fin>>N;
	//calcA();return 0;
	scan(1, N-1, fout);
    return 0;
}