/*
ID: huhan3n1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <math.h>
#include <vector>
using namespace std;

int genInt(stack<int> &nums, int c){
	int l=c-1,r=0,ret=0;
	while(l>=r){
		if(l==r){
			ret+=nums.top()*pow(10, l);	//弹出的数的l次方
		} else {
			ret+=nums.top()*(pow(10,l)+pow(10,r)); 	//弹出的数的l次方+r次方
		}
		nums.pop();
	}
	return ret;
}

bool isPrime(int a){
	if((a%2)==0){
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

void search(int val, int level, stack<int> &nums){
	if(nums.size()>=level/2){
		/** 生成相应的整数*/
		int gen=0;
		
		if(isPrime(gen)){
			cout<<gen<<endl;
		}
	} else {
		nums.push(val);
		for(int i=0;i<10;i++){
			search(i, level, nums);
		}
	}
}

vector<int> s;
int maxv,minv;
void genS(int len, ofstream &fout){
	if(len==0){
		int r=0;
		if(s[0]!=0){
			for(int i=0;i<(s.size()-1);i++){
				r+=s[i]*(pow(10, i)+pow(10, s.size()*2-2-i));
			}
			r+=s[s.size()-1]*pow(10, s.size()-1);
			if(r>=minv && r<=maxv && isPrime(r))
				fout<<r<<endl;
		}
		return;
	}else {
		for(int i=0;i<10;i++){
			s.push_back(i);
			genS(len-1, fout);
			s.pop_back();
		}
	}
}

void genS2(int len, ofstream &fout){
	if(len==0){
		int r=0;
		if(s[0]!=0){
			for(int i=0;i<s.size();i++){
				r+=s[i]*(pow(10, i)+pow(10, s.size()*2-1-i));
			}
			if(r>=minv && r<=maxv && isPrime(r))
				fout<<r<<endl;		
		}
		return;
	}else {
		for(int i=0;i<10;i++){
			s.push_back(i);
			genS2(len-1, fout);
			s.pop_back();
		}
	}
}


int main() {
	int c;
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
	fin>>minv>>maxv;
	for(int i=1;i<=4;i++){
		genS(i, fout);
		genS2(i, fout);
	}
    return 0;
}