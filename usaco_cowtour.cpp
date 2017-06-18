/*
ID: huhan3n1
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

#define MAX_VAL (3000000000)
using namespace std;
int N,ix=0,iy=0;
double X[200], Y[200], Z[200];
double B[200][200]={0},maxv=0;
char t;

bool isDivider(int a){
	for(int i=0;i<N;i++){
		if(B[i][a]!=MAX_VAL&&i!=a){
			return false;
		}
	}
	return true;
}


double dist(int i, int j){
	return sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
}

int main() {
    ofstream fout ("cowtour.out");
    ifstream fin ("cowtour.in");
	fin>>N;
	for(int i=0;i<N;i++){
		fin>>X[ix++];
		fin>>Y[iy++];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			fin>>t;
			//cout<<t;
			if(t=='1'){
				B[i][j]=dist(i, j);
			} else if(i!=j){
				B[i][j]=MAX_VAL;
			}
		}
		//cout<<endl;
	}
	for(int k=0;k<N;k++){	//floyd calc shortest path
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				B[i][j]=B[i][j]<(B[i][k]+B[k][j])?B[i][j]:(B[i][k]+B[k][j]);
			}
		}
	}
	
	for(int i=0;i<N;i++){
		maxv=0;
		for(int j=0;j<N;j++){
			if(B[i][j]!=MAX_VAL)
				maxv=maxv>B[i][j]?maxv:B[i][j];
		}
		Z[i]=maxv;
		//cout<<Z[i]<<endl;
	}
	
	maxv=10000000;
	for(int i=0;i<N;i++){	//make cartesian product
		for(int j=i+1;j<N;j++){
			if(B[i][j]==MAX_VAL){
				//cout<<(Z[i]+Z[j]+dist(i, j))<<endl;
				maxv = maxv<(Z[i]+Z[j]+dist(i, j))?maxv:(Z[i]+Z[j]+dist(i, j));
				//printf("%.06f\t%.06f\t%.06f\t%.06f\t%d\t%d\t\n", (Z[i]+Z[j]+dist(i, j)), Z[i], Z[j], dist(i, j), i ,j);	
			}
		}
	}
	for(int i=0;i<N;i++){
		maxv=maxv>Z[i]?maxv:Z[i];
	}
	
	fout<< std::fixed << std::setprecision(6)<<maxv<<endl;
	//printf("%.06f\n",maxv);
	return 0;
}