/*
ID: huhan3n1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <stdio.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int color_count;
int colors[2*100000];
int path[2*100000][2];
int n=0,a=0,b,c;

int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		fin>>path[a][0];
		fin>>path[a][1];
		a++;
		for(int i=1;i<=color_count;i++){
			b=colors[i]==0?i:colors[i];
			if(isFit()){
				
			}
		}
	}
    return 0;
}