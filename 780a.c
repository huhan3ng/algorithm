#include<cstdio>
using namespace std;

int main(){
  int r=0,n,i,a,m=-1;
  scanf("%d", &n);
  bool f[n+1]={0};
  for(int i=0;i<2*n;i++){
	  scanf("%d", &a);
	  if(f[a]){
		  f[a]=false;
		 r--; 
	  } else {
		  f[a]=true;
		  r++;
	  }
	  if(r>m){
		  m=r;
	  }
  }
  printf("%d\n", m);
  return 0;
}
