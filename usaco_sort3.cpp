/*
ID: huhan3n1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int c2[3][3]={0};

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
	int n=0,c[4]={0},h=0,t=0,a=0,r=0;
	fin>>n;
	int v[n]={0};
	for(int i=0;i<n;i++){
		fin>>v[i];
	}
	for(int i=0;i<n;i++){
		cout<<"+++"<<v[i]<<endl;
		c[v[i]]++;
	}
	for(int i=0;i<3;i++){	//i表示第几个区间，0表示最终1占有的区间,1表示最终2...
		h+=c[i];
		t=h+c[i+1];
		for(int j=h;j<t;j++){
			cout<<"---"<<v[j]<<endl;
			c2[i][v[j]-1]++;
		}
	}
	//1-2,1-3,2-3可对换个数
	a=min(c2[0][1], c2[1][0]);	//1-2对换
	c2[0][1]-=a;
	c2[0][0]+=a;
	c2[1][0]-=a;
	c2[1][1]+=a;
	r+=a;
	a=min(c2[0][2], c2[2][0]);	//1-3对换
	c2[0][2]-=a;
	c2[0][0]+=a;
	c2[2][0]-=a;
	c2[2][2]+=a;
	r+=a;
	a=min(c2[1][2], c2[2][1]);	//2-3对换
	c2[1][2]-=a;
	c2[1][1]+=a;
	c2[2][1]-=a;
	c2[2][2]+=a;
	r+=a;
	//剩下长度为3的置换组/环
	if(c2[0][1])
		r+=2*c2[0][1];
	if(c2[0][2])
		r+=2*c2[0][2];
	fout<<r<<endl;
    return 0;
}