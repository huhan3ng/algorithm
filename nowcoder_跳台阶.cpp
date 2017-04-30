class Solution {
public:
    int jumpFloor(int number) {
		int a1 = 1, a2=1, a=0;
        if(number==0){
            return a1;
        } else if(number==1){
            return a2;
        } else {
            for(int i=2;i<=number;i++){
                a = a2;
                a2 = a1+a2;
                a1 = a;
            }
            return a2;
        }
    }
};