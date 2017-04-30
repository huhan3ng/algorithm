/*
ID: huhan3n1
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int getSum(int bottom, int top, vector<int> &v){
	int count=0;
	for(int i=0;i<v.size();i++){
		if(v[i]<bottom){
			count+=(bottom-v[i])*(bottom-v[i]);
		}
		if(v[i]>top){
			count+=(v[i]-top)*(v[i]-top);
		}
	}
	return count;
}

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
	int n,a,count=0,min=101,max=0,ret=0x0FFFFFFF,t=0;
	string tmp;
	fin>>n;
	vector<int> s(n, 0);
	getline(fin, tmp);
	for(int i=0;i<n;i++){
		fin>>a;
		s[i]=a;
		if(a>=max){
			max=a;
		}
		if(a<=min){
			min=a;
		}
		getline(fin, tmp);
	}
	//cout<<"max: "<<max<<"min: "<<min<<endl;
	if((max-min)<=17){
		fout<<0<<endl;
    	return 0;
	}
	for(int i=min;i<(max-17);i++){
		t=getSum(i, i+17, s);
		//cout<<"sum: "<<t<<endl;
		if(t<ret){
			ret=t;
		}
	}
	fout<<ret<<endl;
    return 0;
}