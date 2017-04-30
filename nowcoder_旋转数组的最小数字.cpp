class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size(),s1=0,s2=0;
        if(len == 0){
            return 0;
        }
        while(len>1){
            //作一个划分
            if(rotateArray[s1+len/2-1]<=rotateArray[s1+len-1]){	//小于取左边，大于取右边
                len = len/2;
            } else {
                s1 = s1+len/2;
                len = len - len/2;
            }
        }
        return rotateArray[s1];
    }
};