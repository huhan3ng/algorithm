/*
ID: huhan3n1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define max(a, b) ((a)>(b)?(a):(b))
using namespace std;

int maxPath(vector<vector<int> > &v, vector<vector<int> > &w, int height, int i, int j){
	if(!height){
		return 0;
	} else {
		if(w[i+1][j]<0){
			w[i+1][j]=maxPath(v, w, height-1, i+1, j);
		}
		if(w[i+1][j+1]<0){
			w[i+1][j+1]=maxPath(v, w, height-1, i+1, j+1);
		}
		return max(v[i][j]+w[i+1][j], v[i][j]+w[i+1][j+1]);
	}
}

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
	int n;
	string tmp;
	fin>>n;
	getline(fin, tmp);
	vector<vector<int> > v(n, vector<int>(n, 0));
	vector<vector<int> > w(n+1, vector<int>(n+1, -1));
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			fin>>v[i][j];
		}
		getline(fin, tmp);
	}
	fout<< maxPath(v, w, n, 0, 0)<<endl;
    return 0;
}