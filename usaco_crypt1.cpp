/*
ID: huhan3n1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool find(vector<int> &p, int key){
	bool ret=false;
	for(int i=0;i<p.size();i++){
		if(p[i]==key){
			ret=true;
			break;
		}
	}
	return ret;
}

bool presentAble(vector<int> &param, int v){
	int t;
	while(v){
		t=v%10;
		for(int i=0;i<param.size();i++){
			if(!find(param, t)){
				return false;
			}
		}
		v=v/10;
	}
	return true;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
	int n,a,b,c,d,e,p1,p2,p3,r=0;
	string tmp;
	fin>>n;
	vector<int> w(n, 0);
	getline(fin, tmp);
	for(int i=0;i<n;i++){
		fin>>w[i];
	}
	
	for(a=0;a<n;a++){
		for(b=0;b<n;b++){
			for(c=0;c<n;c++){
				for(d=0;d<n;d++){
					for(e=0;e<n;e++){
						p1=(w[a]*100+w[b]*10+w[c])*w[e];
						p2=(w[a]*100+w[b]*10+w[c])*w[d];
						p3=p1+p2*10;
						if(p1>=100 
						&& p1<1000 
						&& p2>=100 
						&& p2<1000 
						&& p3>=1000 
						&& p3<10000
						&& presentAble(w, p1)
						&& presentAble(w, p2)
						&& presentAble(w, p3)
						){
							//cout<<"a:"<<w[a]<<" b:"<<w[b]<<endl;
							//cout<<"p1:"<<p1<<"  p2:"<<p2<<"  p3:"<<p3<<endl;
							r++;
						}
					}
				}
			}
		}
	}
	fout<<r<<endl;
    return 0;
}