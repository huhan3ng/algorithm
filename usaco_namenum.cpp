/*
ID: huhan3n1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char inteval[11] = {0,0,'A','D','G','J','M','P','T','W','Z'};

bool checkEqual(string n, string b){
	if(n.length()!=b.length()){
		return false;
	} else {
		//cout<<"----"<<n<<"----"<<b<<endl;
		for(int i=0;i<n.length();i++){
			//if(b=="GREG")
				//cout<<"++++"<<inteval[n[i]-48]<<"----"<<b[i]<<endl;
			if(!(inteval[n[i]-48]<=b[i] && inteval[n[i]-47]>b[i])){
				return false;
			}
		}
		return true;
	}
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fin2 ("dict.txt");
	string tmp,src;
	vector<string> dict;
	int c=0;
	while(std::getline(fin2, tmp)){
		dict.push_back(tmp);
	}
	//cout<<dict.size()<<endl;
	std::getline(fin, src);
	for(int i=0;i<dict.size();i++){
		if(checkEqual(src, dict[i])){
			fout<<dict[i]<<endl;
			c++;
		}
	}
	if(!c){
		fout<<"NONE"<<endl;
	}
    return 0;
}