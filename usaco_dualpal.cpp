/*
ID: huhan3n1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string i2s(int v, int base){
	string ret;
	int r;
	while(v){
		r = v%base;
		//cout<<v%base<<r<<endl;
		if(r<10){
			r=r+48;
		} else {
			r=r+55;
		}
		ret.push_back((char)r);
		v=v/base;
	}
	return ret;
}

bool isPalindrome(string s){
	int i=0;
	while(i<(s.size()-1-i)){
		if(s[i]!=s[s.size()-1-i]){
			return false;
		}
		i++;
	}
	return true;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
	int n,s,b,c,d=0;
	fin>>n>>s;
	for(unsigned int i=s+1;i<((unsigned int)0-1);i++){
		c=0;
		for(b=2;b<=10;b++){
			if(isPalindrome(i2s(i, b))){
				c++;
				if(c>=2){
					fout<<i<<endl;
					d++;
					break;
				}
			}
		}
		if(d>=n){
			break;
		}
	}
    return 0;
}