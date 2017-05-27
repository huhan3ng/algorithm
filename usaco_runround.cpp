/*
ID: huhan3n1
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX_LEN 30
using namespace std;

unsigned char V[MAX_LEN];	//存每一位数字
int LEN;	//存数字长度
bool F2[MAX_LEN];	//循环是存储是否已经走过
bool F1[10];	//判断是否出现0 或重复的数字

bool genF2(){
	int i=0,c=0;
	for(i=0;i<MAX_LEN;i++){
		F2[i]=false;
	}
	i=MAX_LEN-LEN;
	while(!F2[i]){
		F2[i] = true;
		//cout<<(int)V[i]<<"i"<<i<<"--------"<<(((i-(MAX_LEN-LEN)))%LEN)<<endl;
		i = (MAX_LEN-LEN)+((V[i]+(i-(MAX_LEN-LEN)))%LEN);
		c++;
	}
	if(c<LEN || i!=(MAX_LEN-LEN)){	//说明没有遍历满所有点就重复了
		return false;
	} else {
		return true;
	}
}

bool genF1(unsigned long v){
	int tail = MAX_LEN;
	int p;
	LEN=0;
	for(int i=0;i<MAX_LEN;i++){
		V[i]=0;
	}
	for(int i=0;i<10;i++){
		F1[i]=false;
	}
	while(v){
		p = v%10;
		V[--tail]=p;
		v/=10;
		if(p==0 || F1[p]){
			return false;
		} else {
			F1[p] = true;
			LEN++;
		}
	}
	return true;
}

bool isRunaround(unsigned long i){
	if(!genF1(i)){
		//cout<<"f1 false"<<endl;
		return false;
	}
	if(!genF2()){
		//cout<<"f2 false"<<endl;
		return false;
	}
		//cout<<"true i: "<<i<<endl;
	return true;
}

int main() {
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
	unsigned long n,i;
	fin>>n;
	for(i=n+1;;i++){
		if(isRunaround(i)){
			break;
		}
	}
	fout<<i<<endl;
    return 0;
}