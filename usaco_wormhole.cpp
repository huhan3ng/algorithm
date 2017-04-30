/*
ID: huhan3n1
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> x(14,0),y(14,0);
vector<int> w(14,0);//标记当前使用了哪些点了
vector<int> z;	//存放结对的点
vector<int> u(14,0);
int count=0;

int find(int n, vector<int> &p, int key){
	for(int i=0;i<n;i++){
		if(p[i]==key){
			return i;
		}
	}
	return -1;
}

/** 获取数组中最左边的空位*/
int getMin(vector<int> &v, int n){
	int i=0;
	for(;i<n;i++){
		if(!v[i]){
			return i;
		}
	}
	return i;
}

/** 获取右边第一个的虫洞*/
int getRightWorm(int n, int next){
	int ret=-1,t=0x7FFFFFFF;
	for(int i=0;i<n;i++){
		if(y[i]==y[next] && x[i]>x[next] && x[i]<t){
			ret=i;
			t=x[i];
		}
	}
	return ret;
}

/** 穿过虫洞*/
int jumpWorm(int n,int cur){
	int q=find(n, z, cur);
	int ret;
	if(q%2){
		ret=z[q-1];
	} else {
		ret=z[q+1];
	}
	return ret;
}

/** 根据w中存放的点对判断是否存在循环，遍历每一个点，从+x方向走进虫洞*/
bool searchLoop(int n){
	int next,tmp;	//对应 x,y中点的序号
	for(int i=0;i<n;i++){
		std::fill(u.begin(), u.end(), 0);
		next=i;
		u[next]=1;
				//cout<<"开始 "<<next<<endl;
		//cout<<"searchLoop p: "<<i<<endl;
		do{
			next=jumpWorm(n, next);
				//cout<<"jumpWorm "<<next<<endl;
			/**
			if(u[next]){
				cout<<"循环了--------------------count: "<<count<<endl;
				return true;
			} else {
				u[next]=1;
			}
			*/
			next=getRightWorm(n, next);
				//cout<<"getRightWorm "<<next<<endl;
			if(next>=0){			
				if(u[next]){
					//cout<<"循环了--------------------count: "<<count<<endl;
					return true;
				} else {
					u[next]=1;
				}	
			}
		} while(next>=0);
	}
	return false;
}

void sub(int n){
	if(z.size()==n){	//此时完成配对了
		if(searchLoop(n)){
			/**
			for(int i=0;i<z.size();i++){
				cout<<z[i];
			}
			cout<<endl;
			*/
			count++;
		}
		
	} else {
		int t=getMin(w, n);
		z.push_back(t);
		w[t]=1;
		for(int i=t+1;i<n;i++){
			if(!w[i]){
				w[i]=1;
				z.push_back(i);
				sub(n);
				w[i]=0;
				z.pop_back();
			}
		}
		z.pop_back();
		w[t]=0;
	}
}

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
	int n;
	count=0;
	string tmp;
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>x[i]>>y[i];
		//cout<<x[i]<<"  "<<y[i]<<endl;
		getline(fin, tmp);
	}
	sub(n);
	fout<<count<<endl;
	/***************************
	z.push_back(0);
	z.push_back(1);
	z.push_back(2);
	z.push_back(5);
	z.push_back(4);
	z.push_back(3);
	searchLoop(6);
	//int ret = getRightWorm(6, 0);
	//cout<<ret<<endl;
	***************************/
    return 0;
}