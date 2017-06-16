/*
ID: huhan3n1
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int maxd=1, visited=2, W, H, E=0;
int A[202][100]={0};
bool B[202][100];
char t;

void visitAN(int y, int x){
	if(y+1<H && B[y+1][x] && A[y+1][x]==0){
		A[y+1][x]=maxd+1;
		//printf("%d	%d\n", y+1, x);
		visited++;
	}
	if(y-1>=0 && B[y-1][x] && A[y-1][x]==0){
		A[y-1][x]=maxd+1;
		//printf("%d	%d\n", y-1, x);
		visited++;
	}
	if(x+1<W && B[y][x+1] && A[y][x+1]==0){
		A[y][x+1]=maxd+1;
		//printf("%d	%d\n", y, x+1);
		visited++;
	}
	if(x-1>=0 && B[y][x-1] && A[y][x-1]==0){
		A[y][x-1]=maxd+1;
		//printf("%d	%d\n", y, x-1);
		visited++;
	}
}

int main() {
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");
	fin>>W>>H;
	W=2*W+1;
	H=2*H+1;
	for(int y=0;y<H;y++){
		fin>>std::noskipws>>t;
		for(int x=0;x<W;x++){
			fin>>std::noskipws>>t;
			if(t=='+'||t=='-'||t=='|'){
				//cout<<t;
				B[y][x]=false;
			} else if(t==' '){
				//cout<<t;
				if(y==(H-1) || x==(W-1) || y==0 || x==0){
					A[y][x]=maxd;
					//printf("%d	%d\n", y, x);
				}
				E++;
				B[y][x]=true;
			} else {
				cout<<(int)t;
			}
		}
		//cout<<endl;
	}
	
	
	while(visited<E){		
		for(int y=0;y<H;y++){
			for(int x=0;x<W;x++){
				if(maxd==A[y][x]){
					visitAN(y, x);
				}
			}
		}
		maxd++;
	}
	fout<<maxd/2<<endl;
	return 0;
}