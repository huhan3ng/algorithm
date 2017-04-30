/*
ID: huhan3n1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define mod(x, m) ((((x)%(m))+(m))%(m))
using namespace std;

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
	int n,r=0;
	string tmp;
	fin>>n;
	vector<int> a(n, 0),b(n, 0);
	getline(fin, tmp);
	fin>>a[0]>>a[1]>>a[2];
	//cout<<a[0]<<a[1]<<a[2]<<endl;
	getline(fin, tmp);
	fin>>b[0]>>b[1]>>b[2];
	//cout<<b[0]<<b[1]<<b[2]<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(((mod(i-a[0], n)<=2||mod(a[0]-i, n)<=2)
					&& (mod(j-a[1], n)<=2||mod(a[1]-j, n)<=2)
					&& (mod(k-a[2], n)<=2||mod(a[2]-k, n)<=2))
					|| ((mod(i-b[0], n)<=2||mod(b[0]-i, n)<=2)
					&& (mod(j-b[1], n)<=2||mod(b[1]-j, n)<=2)
					&& (mod(k-b[2], n)<=2||mod(b[2]-k, n)<=2))){
					//cout<<i<<","<<j<<","<<k<<endl;
					r++;
				}
			}
		}
	}
	fout<<r<<endl;
    return 0;
}