#include<math.h>
class Solution {
    public:
        int NumberOf1Between1AndN_Solution(int n)
        {
            int a=0,b=0,c=0,i=0,j=0,r=0,x=0;	//5678= 0~4999 + 5000~5599 + 5600~5669 + 5670~5678
			do{
                r=n%10;
                if(r==1){
                    x=x+(c+1)+r*b;
                } else if(r>1){
                    x=x+pow(10,i)+r*b;
                }
                b=pow(10, i)+b*10;
                c= r*pow(10, i)+c;
                i++;
                n=n/10;
            } while(n>0);
            return x;
        }
	
};