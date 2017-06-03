/*
ID: huhan3n1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include  <iomanip>
using namespace std;
int N,C;	//原数据集大小，操作次数

vector<int> must_on;
vector<int> must_off;

unsigned char V[20][104]={0};
int count=0;
unsigned char D[104];

void oper1(){
	for(int i=1;i<=N;i++){
		D[i] = D[i]==0?1:0;
	}
}

void oper2(){
	for(int i=1;i<=N;i+=2){
		D[i] = D[i]==0?1:0;
	}
}

void oper3(){
	for(int i=2;i<=N;i+=2){
		D[i] = D[i]==0?1:0;
	}
}

void oper4(){
	for(int i=1;i<=N;i+=3){
		D[i] = D[i]==0?1:0;
	}
}

void clearD(){
	for(int i=1;i<104;i++){
		D[i]=1;
	}
}

void dumpD(int k){
	for(int i=1;i<=N;i++){
		//cout<<(int)D[i];
		V[k][i] = D[i];
	}
	V[k][0]=1;
	count++;
	//cout<<"k: "<<k<<"   "<<V[k][0]<<endl;
}

void check(int k){
	for(int i=0;i<must_on.size();i++){
		if(D[must_on[i]] != 1){
			clearD();
			return;
		}
	}
	for(int i=0;i<must_off.size();i++){
		if(D[must_off[i]] != 0){
			clearD();
			return;
		}
	}
	dumpD(k);
	clearD();
	return;
}


int main() {
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
	fin>>N>>C;
	int t;
	while(1){
		fin>>t;
		if(t==-1){
			break;
		}
		must_on.push_back(t);
	}
	while(1){
		fin>>t;
		if(t==-1){
			break;
		}
		must_off.push_back(t);
	}
	clearD();
	//cout<<"N: "<<N<<"C: "<<C<<endl;
	while(C>=0){
		if(C==0){
			check(0);
		} else if(C==1){
			oper1();check(8);
			oper2();check(6);
			oper3();check(3);
			oper4();check(5);
		} else if(C==2){
			oper1();oper2();check(3);
			oper1();oper3();check(6);
			oper1();oper4();check(4);
			oper2();oper3();check(8);
			oper2();oper4();check(2);
			oper3();oper4();check(7);
		} else if(C==3){
			oper1();oper2();oper3();check(1);
			oper1();oper2();oper4();check(7);
			oper1();oper3();oper4();check(2);
			oper2();oper3();oper4();check(4);
		} else if(C==4){
			oper1();oper2();oper3();oper4();check(5);
		}
		C-=2;
	}
	if(count==0){
		fout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	for(int i=20;i>=0;i--){
		if(V[i][0]==1){
			for(int j=1;j<=N;j++){
				fout<<(int)V[i][j];
			}
			fout<<endl;
		}
	}
    return 0;
}