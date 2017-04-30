class Solution {
    vector<int> ret,s,e,l;
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int a;
        if(input.size()<k){
            return ret;
        }
        while(input.size()>k){
            s.clear();
            l.clear();
            e.clear();
            for(int i=0;i<input.size();i++){
                a = input[input.size()/2];
                if(input[i]>a){
                    l.push_back(input[i]);
                } else if(input[i]<a){
                    s.push_back(input[i]);
                } else {
                    e.push_back(input[i]);
                }
            }
            if(k<s.size()){
                input.assign(s.begin(),s.end());
            } else if(k<=(s.size()+e.size())){
                ret.insert(ret.end(), s.begin(), s.end());
                for(int i=0;i<k-s.size();i++){
                    ret.push_back(e[i]);
                }
                return ret;
            } else {	//k> s.size()+e.size();
                ret.insert(ret.end(), s.begin(), s.end());
                ret.insert(ret.end(), e.begin(), e.end());
                input.assign(l.begin(),l.end());
                k=k-s.size()-e.size();
            }
        }
        for(int i=0;i<input.size();i++){
            ret.push_back(input[i]);
        }
        return ret;
    }
};