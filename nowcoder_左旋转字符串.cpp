class Solution {
public:
    string LeftRotateString(string str, int n) {
		int len=str.length();
        string ret(len, ' ');
        for(int i=0;i<len;i++){
            ret[((i-n)%len+len)%len] = str[i];
        }
        return ret;
    }
};