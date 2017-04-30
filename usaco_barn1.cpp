/*
ID: huhan3n1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int max(vector<int> &data){
	int ret=0;
	int ret2=0;
	for(int i=0;i<data.size();i++){
		if(data[i]>=ret){
			ret=data[i];
			ret2=i;
		}
	}
	return ret2;
}

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
	int m,s,c,w,v=0,t,l=0,vmax,vmin;
	string tmp;
	fin>>m>>s>>c;
	if(m>=c){
		fout<<c<<endl;
		return 0;
	}
	vector<char> r(s+1,0);
	vector<int> z;
	getline(fin, tmp);
	for(int i=0;i<c;i++){
		fin>>t;
		r[t]=1;
		getline(fin, tmp);
	}
	for(int i=0;i<=s;i++){
		if(r[i]){
			if(l!=0){
				z.push_back(i-l-1);
				//cout<<i-l-1<<endl;
			} else {
				vmin=i;
			}
			l=i;
		}
	}
	vmax=l;
	for(int i=0;i<(m-1);i++){
		t=max(z);
		v+=(z[t]);
		z[t]=0;
	}
	//cout<<vmin<<"  "<<vmax<<" "<<v<<endl;
	fout<<vmax+1-vmin-v<<endl;
    return 0;
}