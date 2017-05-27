/*
ID: huhan3n1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define min(a, b) ((a)<(b)?(a):(b))
int V,G,v[25]/**对每种维生素的需求*/,t[15][25]/**每种饲料提供的维生素含量*/;
vector<int> x;

void dump(vector<int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

bool check(){
	int val;
	for(int i=0;i<V;i++){	//遍历维生素
		val=0;
		for(int j=0;j<G;j++){	//遍历饲料
			val+=t[j][i]*x[j];
		}
		//cout<<"val: "<<val<<"vi: "<<v[i]<<endl;
		if(val<v[i]){
			return false;
		}
	}
	return true;
}

bool genX(int sum, int rn){
	//cout<<"sum: "<<sum<<"rn "<<rn<<endl;
	if(rn==1){	//G-1个x都选定了
		x.push_back(min(1,sum));
		//dump(x);
		if(check()){
			//cout<<"---"<<endl;
			return true;
		} else {
			x.pop_back();
			return false;
		}
	}else{
		for(int i=min(1,sum);i>=0;i--){
			x.push_back(i);
			if(genX(sum-i, rn-1)){
				return true;
			}
			x.pop_back();
		}
		return false;
	}
}


int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
	fin>>V;
	for(int i=0;i<V;i++){
		fin>>v[i];
	}
	fin>>G;
	for(int i=0;i<G;i++){
		for(int j=0;j<V;j++){
			fin>>t[i][j];
		}
	}
	int sum;
	for(sum=1;sum<=G;sum++){
		if(genX(sum, G)){
			break;
		}
	}
	fout<<(sum);
	for(int i=0;i<G;i++){
		if(x[i])
			fout<<" "<<(i+1);
	}
	fout<<endl;
	//dump(x);
	return 0;
}