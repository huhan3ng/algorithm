/*
ID: huhan3n1
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int A[200000]={0};
char B[200][12]={0};
char C[200000]={0};
int lena=0,lenb=0,lenc=0;

int match(int ic, int ib){
	int i=0;
	while(B[ib][i]){
		if(B[ib][i]!=C[ic+i]){
			return -1;
		}
		i++;
	}
	return i;
}

int main() {
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
	while(1){
		fin>>B[lenb];
		if(B[lenb][0]=='.'){
			break;
		}
		lenb++;
	}
	while(1){
		fin>>C[lenc];
		if(C[lenc]==0){
			break;
		} else {
			lenc++;
		}
	}
	int val,max;
	for(int i=lenc-1;i>=0;i--){
		max=0;
		for(int j=0;j<lenb;j++){
			val = match(i,j);
			if(val>0){
				val+=A[i+val];
				max = val>max?val:max;
			}
		}
		A[i]=max;
		//cout<<"A["<<i<<"]="<<max<<endl;
	}
	fout<<A[0]<<endl;
	return 0;
}