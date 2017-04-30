/*
ID: huhan3n1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int days[2][12]={{31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}};
int isLeapYear(int year){
	if(year%100==0){
		if(year%400==0){
			return 0;
		} else {
			return 1;
		}
	} else {
		if(year%4==0){
			return 0;
		} else {
			return 1;
		}
	}
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
	int n,s=0,t=0;
	int r[7]={0};
	fin>>n;
	for(int i=1900;i<(1900+n);i++){
		t = isLeapYear(i);
		for(int j=0;j<12;j++){
			r[(s+13-6)%7]++;
			s = (s+days[t][j])%7;	//一周7天
		}
	}
	for(int i=0;i<6;i++){
		fout<<r[i]<<' ';
	}
	fout<<r[6]<<endl;
    return 0;
}