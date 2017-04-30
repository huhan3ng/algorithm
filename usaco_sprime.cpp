/*
ID: huhan3n1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

bool isPrime(int a){
	if(a==1){
		return false;
	} else if(a==2){
		return true;
	} else if((a%2)==0){
		return false;
	} else {
		for(int i=3;i<=sqrt(a);i+=2){
			if((a%i)==0){
				//cout<<i<<endl;
				return false;
			}
		}		
	}

	return true;
}

void gen(int cv, int l, ofstream &fout){
	if(!l){
		fout<<cv<<endl;
	} else {
		for(int i=0;i<10;i++){
			//cout<<"---"<<cv*10+i<<endl;
			if(isPrime(cv*10+i)){
				gen(cv*10+i, l-1, fout);
			}
		}
	}
}

int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
	int n;
	fin>>n;
	gen(0, n, fout);
    return 0;
}