#include<cstdio>
#define max(a,b)  (((a) > (b)) ? (a) : (b))

using namespace std;

bool reachable(double time, int a[], int b[], int n, double max, double min){
	double h=min, t=max;
	for(int i=0;i<n;i++){
		if((a[i]-b[i]*time)>=h){
			h=a[i]-b[i]*time;
		}
		if((a[i]+b[i]*time)<=t){
			t=a[i]+b[i]*time;
		}
		if(h>t){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	double up, down,c,maxL=0,minL=1000000000,minS=1;
	scanf("%d", &n);
	int a[n]={0};
	int b[n]={0};
	for(int i=0;i<n;i++){
		scanf("%d", a+i);
		if(a[i]>maxL){
			maxL=a[i];
		}
		if(a[i]<minL){
			minL=a[i];
		}
	}
	for(int i=0;i<n;i++){
		scanf("%d", b+i);
		if(a[i]<minS){
			minS=a[i];
		}
	}
	up=(maxL-minL)/minS;
	down=0;
	//printf("%lf %lf\r\n", up, down);
	while((up-down)*1000000/max(1, down)>1){
		if(reachable((up+down)/2, a, b, n, maxL, minL)){
			up=(up+down)/2;
		} else {
			down=(up+down)/2;
		}
	//printf("%lf %lf\r\n", up, down);
	}
	
	printf("%0.12f", (down+up)/2);
	return 0;
}
