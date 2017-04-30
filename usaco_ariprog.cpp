/*
ID: huhan3n1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int glee[135001]={0};
bool presentAble(int a, int M){
	if(glee[a]>0){
		return true;
	} else if(glee[a]<0){
		return false;
	}
	for(int p=0;(p<=M);p++){
		for(int q=0;a>=(p*p+q*q)&& q<=M;q++){
			if(a==(p*p+q*q)){
				glee[a]=1;
				return true;
			}
		}
	}
	glee[a]=-1;
	return false;
}

bool check(int a, int b, int n, int M){
	//cout<<"true :""a: "<<a<<";  b: "<<b<<";  M: "<<M<<";  n: "<<n<<endl;
	for(int i=0;i<n;i++){
		if(!glee[a+i*b]){
			return false;
		}
	}
	return true;
	/**
		if(n==0){
		cout<<"true :""a: "<<a<<";  b: "<<b<<";  M: "<<M<<";  n: "<<n<<endl;
		return true;
	}
	if(!presentAble(a, M)){
		cout<<"true :""a: "<<a<<";  b: "<<b<<";  M: "<<M<<";  n: "<<n<<endl;
		return false;
	} else {
		return check(a+b, b, n-1, M);
	}
	*/
}

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
	string tmp;
	int n,M,i=0;
	fin>> n;
	getline(fin, tmp);
	fin>> M;
	
	for(int p=0;p<=M;p++){
		for(int q=0;q<=M;q++){
			glee[p*p+q*q]=1;
			//cout<<p*p+q*q<<endl;
		}
	}
	//cout<<2*M*M/(n-1)<<" "<<(2*M*M-n*4)<<endl;
	//return 0;
	for(int b=1;b<=5000;b++){
		for(int x=0;x<((M*M)/b);x++){	//n
			for(int y=0;y<b;y++){	//模
				//cout<<y<<" "<<x<<" "<<b<<endl;
				if(check(y+x*b, b, n, M)){
					i++;
					fout<<y+x*b<<" "<<b<<endl;
				}
			}
		}
	}
	if(i==0){
		fout<<"NONE"<<endl;
	}
    return 0;
}

