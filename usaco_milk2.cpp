/*
ID: huhan3n1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define max(a,b) ((a)>(b))?(a):(b) 
#define min(a,b) ((a)>(b))?(b):(a) 
using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
	char x[1000000] = {0};
	string tmp;
	int n,h,t,c=0,s1=-1,m1=0,s2=-1,m2=0,imax=0,imin=1000000;
	fin>>n;
	//cout<<"++n:"<<n<<endl;
	std::getline(fin, tmp);
	for(int i=0;i<n;i++){
		fin>>h>>t;
		imin=min(h, imin);
		imax=max(t, imax);
		//cout<<"++h:"<<h<<"  t:"<<t<<endl;
		std::getline(fin, tmp);
		x[h]++;
		x[t]--;
	}
	for(int i=imin;i<=imax;i++){
		c+=x[i];
		if(s1==-1 && c>0){	//未计数状态开始计数
			s1=1;
		} else if(s1!=-1 && c>0){	//计数中继续计数
			s1++;
		} else if(s1!=-1 && c==0){	//计数中中断计数
			m1=max(s1,m1);
			s1=-1;
		}
		if(s2==-1 && c==0){	//未计数状态开始计数
			s2=1;
		} else if(s2!=-1 && c==0){	//计数中继续计数
			s2++;
			//cout<<"---"<<s2<<endl;
		} else if(s2!=-1 && c!=0){	//计数中中断计数
			m2=max(s2,m2);
			s2=-1;
		}
	}
	//cout<<m1<<"  "<<m2<<endl;
	fout<<m1<<' '<<m2<<endl;
    return 0;
}