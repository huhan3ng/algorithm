/*
ID: huhan3n1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define mod(v, m) (((v)%(m)+(m))%(m))
using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
	int n,c,i,j,sum,max=0;
	char t;
	string s;
	fin>>n;
	std::getline(fin, s);
	std::getline(fin, s);
	for(c=0;c<n;c++){
		sum=0;
		t=s[mod(i-1,n)];
		for(i=c,j=c;((j-i)<n && (s[mod(i-1,n)]=='w'||s[mod(i-1,n)]==t||t=='w'));i--){
			sum++;
			if(t=='w'){
				t=s[mod(i-1,n)];
			}
		}
		t=s[c%n];
		for(j=c;((j-i)<n && (s[j%n]==t||s[j%n]=='w'||t=='w'));j++){
			sum++;
			if(t=='w'){
				t=s[j%n];
			}
		}
		max=max>sum?max:sum;
	}
	cout<<max<<endl;
	fout<<max<<endl;
	return 0;
}