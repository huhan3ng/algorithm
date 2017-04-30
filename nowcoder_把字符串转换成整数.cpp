class Solution {
public:
    int StrToInt(string str) {
        int e=1,k=0,j=1,t;
        for(int i=str.length()-1;i>=0;i--,j=j*10){
            t=str[i]-48;
            if(t>=0&&t<=9){
                k+=t*j;
            } else {
                if(i==0 && t==('+'-48)){
                    e=1;
                } else if(i==0 && t==('-'-48)){
                    e=-1;
                } else {
                    return 0;
                }
            }
        }
        return e*k;
    }
};