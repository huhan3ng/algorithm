/*
ID: huhan3n1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void rotate90(int x, int y, int &dx, int &dy, int n){
	dx=y;
	dy=n-1-x;
	return;
}

void rotate180(int x, int y, int &dx, int &dy, int n){
	dy=n-1-y;
	dx=n-1-x;
	return;
}

void rotate270(int x, int y, int &dx, int &dy, int n){
	dy=x;
	dx=n-1-y;
}

void reflect(int x, int y, int &dx, int &dy, int n){
	dy=n-1-y;
	dx=x;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
	bool flag;
	string tmp;
	int n=0, dx,dy;
	fin>>n;
	std::getline(fin, tmp);
	char A[n][n], B[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fin>>A[i][j];
			//cout<<A[i][j];
		}
		//cout<<endl;
		std::getline(fin, tmp);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fin>>B[i][j];
			//cout<<B[i][j];
		}
		//cout<<endl;
		std::getline(fin, tmp);
	}
	
	/**旋转90*/
	flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			rotate90(i, j, dx, dy, n);
			if(B[dx][dy]!=A[i][j]){
				flag=false;
				break;
			}
		}
	}
	if(flag){
	fout<<1<<endl;
		return 0;
	}
	
	/** 旋转180*/
	flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			rotate180(i, j, dx, dy, n);
			if(B[dx][dy]!=A[i][j]){
				flag=false;
				break;
			}
		}
	}
	if(flag){
	fout<<2<<endl;
		return 0;
	}
	
	/** 旋转270*/
	flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			rotate270(i, j, dx, dy, n);
			if(B[dx][dy]!=A[i][j]){
				flag=false;
				break;
			}
		}
	}
	if(flag){
	fout<<3<<endl;
		return 0;
	}
	
	/**对称*/
	flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			reflect(i, j, dx, dy, n);
			if(B[dx][dy]!=A[i][j]){
				flag=false;
				break;
			}
		}
	}
	if(flag){
	fout<<4<<endl;
		return 0;
	}
	
	/**对称旋转90*/
	flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			reflect(i, j, dx, dy, n);
			rotate90(dx, dy, dx, dy, n);
			if(B[dx][dy]!=A[i][j]){
				flag=false;
				break;
			}
		}
	}
	if(flag){
	fout<<5<<endl;
		return 0;
	}
	
	/**对称旋转180*/
	flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			reflect(i, j, dx, dy, n);
			rotate180(dx, dy, dx, dy, n);
			if(B[dx][dy]!=A[i][j]){
				flag=false;
				break;
			}
		}
	}
	if(flag){
	fout<<5<<endl;
		return 0;
	}
		
	/**对称旋转270*/
	flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			reflect(i, j, dx, dy, n);
			rotate270(dx, dy, dx, dy, n);
			if(B[dx][dy]!=A[i][j]){
				flag=false;
				break;
			}
		}
	}
	if(flag){
	fout<<5<<endl;
		return 0;
	}
	
	/**no changes*/
	flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dx=i;
			dy=j;
			if(B[dx][dy]!=A[i][j]){
				flag=false;
				break;
			}
		}
	}
	if(flag){
	fout<<6<<endl;
		return 0;
	}
	fout<<7<<endl;
    return 0;
}


