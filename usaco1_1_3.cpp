/*
ID: huhan3n1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
	string comet,group;
	int r1=1,r2=1;
	std::getline(fin, comet);
	std::getline(fin, group);
	for(int i=0;i<comet.length();i++){
		r1=r1*((int)(comet[i]-64))%47;
	}
	for(int i=0;i<group.length();i++){
		r2=r2*((int)(group[i]-64))%47;
	}
	if(r1==r2){
		fout<<"GO"<<endl;
	} else {
		fout<<"STAY"<<endl;
	}
    return 0;
}