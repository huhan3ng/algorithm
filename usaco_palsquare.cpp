/*
ID: huhan3n1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
	int b;
	string cs,cd;
	fin>>b;
	for(int i=1;i<300;i++){
		//cout<<i<<endl;
		cd = i2s(i*i, b);
		if(isPalindrome(cd)){
			cs = i2s(i, b);
			std::reverse(cs.begin(), cs.end());
			std::reverse(cd.begin(), cd.end());
			fout<<cs<<' '<<cd<<endl;
		}
	}
    return 0;
}