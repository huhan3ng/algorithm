class Solution {
public:
    int Fibonacci(int n) {
		int a1 = 0, a2=1, a=0;
        if(n==0){
            return a1;
        } else if(n==1){
            return a2;
        } else {
            for(int i=2;i<=n;i++){
                a = a2;
                a2 = a1+a2;
                a1 = a;
            }
            return a2;
        }
    }
};