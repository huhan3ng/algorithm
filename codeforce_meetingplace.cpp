/*
ID: huhan3n1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <stdio.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int n,tmp=0;
double limit_up=0,limit_down=0,limit_mid=0,head=0,tail=1000000000;
int pos[60000]={0};
int spd[60000]={0};

bool reachable(double time){
	head=0;
	tail=1000000000;
	for(int i=0;i<n;i++){
		head=max(head, pos[i]-time*spd[i]);
		tail=min(tail, pos[i]+time*spd[i]);
		//cout<<"head		"<<head<<"tail		"<<pos[i]-time*spd[i]<<"		"<<time<<endl;
		if(head>tail){
			return false;
		}
	}
	return true;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>pos[i];
		tmp=max(tmp, pos[i]);
	}
	for(int i=0;i<n;i++){
		cin>>spd[i];
	}
	limit_up=tmp;
	while((limit_up-limit_down)*1000000>1){
	//cout<<limit_up<<"	"<<limit_down<<endl;
		limit_mid=(limit_down+limit_up)/2;
		if(reachable(limit_mid)){
			//cout<<"reachable		"<<limit_mid<<"head		"<<head<<"tail		"<<tail<<endl;
			limit_up=limit_mid;
		} else {
			//cout<<"can not reach	"<<limit_mid<<"head		"<<head<<"tail		"<<tail<<endl;
			limit_down=limit_mid;
		}
	}
	printf("%.12lf\n", limit_mid);
    return 0;
}