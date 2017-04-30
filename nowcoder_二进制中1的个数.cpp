class Solution {
public:
     int  NumberOf1(int n) {
         //不清楚32位还是64位CPU，暂时用判断是否为0
         unsigned int a = 0;
         int count=0;
         a = (a-1)/2;	//a最高位为0，其他位都为1
         a = ~a;	//a最高位位1，其他位为0
         while(n!=0){
             if((n&a) != 0){
                 count++;
             }
             n = n << 1;
         }
         return count;
     }
};