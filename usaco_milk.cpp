/*
ID: huhan3n1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX_PRICE 1001;
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;


int min(vector<int> &data){
	int ret=1001;
	int ret2=0;
	for(int i=0;i<data.size();i++){
		if(data[i]<ret){
			ret=data[i];
			ret2=i;
		}
	}
	return ret2;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
	string tmp;
	int n,m,a,b,v=0,t;
	fin>>n>>m;
	getline(fin, tmp);
	vector<int> pricePerUnit(m, 0);
	vector<int> unitsAvailable(m, 0);
	for(int i=0;i<m;i++){
		fin>>pricePerUnit[i]>>unitsAvailable[i];
		getline(fin, tmp);
	}
	while(n>0){
		b=min(pricePerUnit);
		if(unitsAvailable[b]>=n){
			v+=pricePerUnit[b]*n;
			unitsAvailable[b]-=n;
			n-=n;
		} else {
			v+=pricePerUnit[b]*unitsAvailable[b];
			pricePerUnit[b]=MAX_PRICE;
			n-=unitsAvailable[b];
			unitsAvailable[b]=0;
		}
		
	}
	fout<<v<<endl;
    return 0;
}