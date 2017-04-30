class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0){
            return 1;
        }else if(exponent>0){
            exponent--;
            int a = base;
            while(exponent>0){
                base = base*a;
                exponent = exponent-1;
            }
            return base;   
        } else {
            exponent = exponent*(-1);
            exponent--;
            int a = base;
            while(exponent>0){
                base = base*a;
                exponent = exponent-1;
            }
            return 1/base;   			            
        }
    }
};