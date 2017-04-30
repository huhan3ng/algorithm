class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<int> tmp;
        vector<vector<int>> ret;
        if(sum<=2){
            return ret;
        }
        for(int len=(sum-1);len>1;len--){
            if(len%2){//len奇数
                if((sum%len)==0){
                    if((sum/len-(len-1)/2)>0){                     
                        tmp.clear();
                        for(int i=(sum/len-(len-1)/2);i<=(sum/len+(len-1)/2);i++){
                            tmp.push_back(i);
                        }
                        ret.push_back(tmp);	//多一次内存拷贝，可优化
                    }
                }
            } else {	//len偶数
                if((sum%(len/2))==0 && (sum/(len/2))%2==1){	// sum除以len一半是奇数
                    int midLeft=(sum/(len/2))/2;
                    if((midLeft-len/2)>=0){
                        tmp.clear();
                     	for(int i=(midLeft-len/2+1);i<=(midLeft+len/2);i++){
                            tmp.push_back(i);
                        }
                        ret.push_back(tmp);
                    }
                }
            }
        }
        return ret;
    }
};