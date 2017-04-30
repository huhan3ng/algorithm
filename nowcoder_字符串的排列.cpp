class Solution {
    vector<int> v;
    vector<char> ret;
    vector<string> retStr;
public:
    vector<string> Permutation(string str) {
        v = vector<int>(100,0);
        string::iterator iter;
        for(iter = str.begin();iter != str.end();iter++){
            v[*iter-97]++;
        }
        subPermute(str.size());
        return retStr;
    }
    
    void subPermute(int remain){
        if(remain==0){
            if(!ret.empty()){
	            retStr.push_back(string(ret.begin(), ret.end()));
            }
        } else {
            for(int i=0;i<v.size();i++){
                if(v[i]>0){
                    v[i]--;
                    ret.push_back(i+97);
                    subPermute(remain-1);
                    ret.pop_back();
                    v[i]++;
                }
            }            
        }
        
    }
};