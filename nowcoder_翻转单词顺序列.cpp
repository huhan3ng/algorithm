class Solution {
public:
    string ReverseSentence(string str) {
    	int k=0,i=0,div=str.length(), j=0;
        string ret(str.length(), ' ');
        for(i=str.length()-1;i>=0;i--){
            if(str[i]==' '){
				for(j=i+1;j<div;j++){
                    ret[k++]=str[j];
                }
                ret[k++]=' ';
                div=i;
            }
        }
		for(j=i+1;j<div;j++){
			ret[k++]=str[j];
		}
        return ret;
    }
};