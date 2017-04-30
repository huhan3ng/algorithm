/*
ID: huhan3n1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int getNameIndex(vector<string> names, string key, int length){
	for(int i=0;i<length;i++){
		if(names[i]==key)
			return i;
	}
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
	int n=0,k=0,v=0,c=0;
	fin >> n;
	int values[n]={0};
	vector<string> names(n, string(14, 0));
	string giver(14, 0), receiver(14, 0), tmp(14, 0);
	std::getline(fin, tmp);
	for(int i=0;i<n;i++){
		std::getline(fin, names[i]);
		//cout<<names[i]<<endl;
	}
	for(int i=0;i<n;i++){
		std::getline(fin, giver);
		//cout<<giver<<endl;
		k=getNameIndex(names, giver, n);
		fin>>v>>c;
		std::getline(fin, tmp);
		for(int j=0;j<c;j++){
			std::getline(fin, receiver);
			//cout<<receiver<<endl;
			if(c)
				values[getNameIndex(names, receiver, n)]+=v/c;
		}
		if(c)
			values[k]-=v/c*c;
	}
	for(int i=0;i<n;i++){
		fout<<names[i]<<' '<<values[i]<<endl;
	}
    return 0;
}