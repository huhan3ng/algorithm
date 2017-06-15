/*
ID: huhan3n1
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
bool isFloop=false;
bool isCloop=false;

bool A[10][10];
bool F[10][10][4]={false};
bool C[10][10][4]={false};

int D[4][2]={{0, -1},{1,0},{0, 1},{-1,0}};

int xf=0,xc=0,yf=0,yc=0,df=0,dc=0,tx=0,ty=0;	//方向
int lfx,lfy,lcx,lcy, directc, directf;
char t;
bool firstIn=true;;

bool outOfBound(int x, int y){
	if(x<0 || x>=10){
		return true;
	}
	if(y<0 || y>=10){
		return true;
	}
	return false;
}

int main() {
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");
	for(int y=0;y<10;y++){
		for(int x=0;x<10;x++){
			fin>>t;
			if(t=='*'){
				A[y][x]=false;
			} else if(t=='F'){
				xf=x;
				yf=y;
				A[y][x]=true;
			} else if(t=='C'){
				xc=x;
				yc=y;
				A[y][x]=true;
			} else {
				A[y][x]=true;
			}
		}
	}
	int cnt=0;
	while(1){
		cnt++;
		ty=yf+D[df][1];
		tx=xf+D[df][0];
		if(!outOfBound(ty, tx) && A[ty][tx]){
			xf=tx;
			yf=ty;
			if(F[yf][xf][df]){
				isFloop=true;
			} else {
				F[yf][xf][df]=true;
			}
		} else {
			df=(df+1)%4;
		}
		//printf("									xf: %d	yf: %d	xc: %d	yc: %d\n", xf, yf, xc, yc);
		ty=yc+D[dc][1];
		tx=xc+D[dc][0];
		if(!outOfBound(ty, tx) && A[ty][tx]){
			xc=tx;
			yc=ty;
			if(C[yc][xc][dc]){
				isCloop=true;
			} else {
				C[yc][xc][dc]=true;
			}
		} else {
			dc=(dc+1)%4;
		}
		if(xf==xc && yf==yc){
			fout<<cnt<<endl;
			return 0;
		}
		
		if(isFloop && isCloop){
			if(firstIn){				
				lcx = xc;
				lcy = yc;
				lfx = xf;
				lfy = yf;
				firstIn = false;
				//printf("xf: %d	yf: %d	xc: %d	yc: %d\n", xf, yf, xc, yc);
			} else {
				//printf("-----xf: %d	yf: %d	xc: %d	yc: %d\n", xf, yf, xc, yc);
				if(xc==lcx && yc==lcy && xf==lfx && yf==lfy){
					fout<<0<<endl;
					return 0;
				}
			}
		}
	}
	
	
	
	
	fout<<0<<endl;
	
    return 0;
}