class Solution {
public:	//man ascii, A-Z对应值为65~90 !!!!!会出现小写字母 A-z 65-122
    int FirstNotRepeatingChar(string str) {
        int i=0,j=0,min=str.size();
        int num[58]={0};
        int sPos[58]={0};
        for(i=0;i<str.size();i++){
            sPos[str[i]-65]=i;
            num[str[i]-65]++;
        }
        for(j=0;j<58;j++){
            if(num[j]==1 && sPos[j]<min){
                min=sPos[j];
            }     
        }
        if(min==str.size()){
            return -1;
        } else {
            return min;
        }
    }
};