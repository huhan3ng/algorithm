class Solution {
public:
    bool match(char* str, char* pattern)
    {
    	if((*pattern==0) && (*str==0)){
            return true;
        } else {
            if((*pattern!=0) && (*(pattern+1)=='*')){	//如果后面跟了*
                if(*str && ((*str == *pattern) || (*pattern == '.'))){	//如果约str
                    return match(str+1, pattern) || match(str+1, pattern+2) || match(str, pattern+2);
                } else {	//不约str
                    return match(str, pattern+2);
                }
            } else if(*str==0){
                return false;
            } else {	//后面不跟*
                if((*str == *pattern)  || (*pattern == '.')){
                    return match(str+1, pattern+1);
                } else {
                    return false;
                }
            }
        }
    }
};