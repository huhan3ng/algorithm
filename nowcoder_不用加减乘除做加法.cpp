class Solution {
public:
    int Add(int num1, int num2)
    {
		unsigned int mask=1,a,b,c=0,d=0;
        while(mask){
            a=mask&num1;
            b=mask&num2;
            if((a!=0 && b==0 && c==0) || (a==0 && b!=0 && c==0) || (a==0 && b==0 && c!=0)){
                d=d|mask;
                c=0;
            } else if((a!=0 && b!=0 && c==0) || (a==0 && b!=0 && c!=0) || (a!=0 && b==0 && c!=0)){
                c=1;
            } else if(a!=0 && b!=0 && c!=0){
                c=1;
                d=d|mask;
            } else {
                c=0;
            }
            mask = mask<<1;
        }
        return (int)d;
    }
};