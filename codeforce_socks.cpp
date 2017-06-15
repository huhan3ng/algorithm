/*
ID: huhan3n1
PROG: nocows
LANG: C++
*/
#include <iostream>
using namespace std;
int n,c=0,a,max_val=0;
bool flag[2*100000]={false};


int main() {
    cin>>n;
	for(int i=0;i<2*n;i++){
		cin>>a;
		if(flag[a]){
			c--;
			flag[a]=false;
		} else {
			c++;
			flag[a]=true;
			max_val=c>max_val?c:max_val;
		}
	}
	cout<<max_val<<endl;
    return 0;
}