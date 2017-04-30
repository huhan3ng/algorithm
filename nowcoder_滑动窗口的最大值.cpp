class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
		vector<int> m1(num.size(), 0);
		vector<int> m2(num.size(), 0);
        vector<int> ret;
        int h,t,c;
        if(num.size()<size || size==0){
            return ret;
        }
        for(int i=0;i<num.size();i++){
            if(i%size==0 || m1[i-1]<num[i]){
                m1[i]=num[i];
            } else {
                m1[i]=m1[i-1];
            }
        }
        for(int i=num.size()-1;i>=0;i--){
            if((i+1)%size==0 || i==(num.size()-1) || m2[i+1]<num[i]){
                m2[i]=num[i];
            } else {
                m2[i]=m2[i+1];
            }
        }
        for(h=0;h<=num.size()-size;h++){
            t=h+size;
            c=(t/size)*size;
            if(t==c){
                ret.push_back(m1[t-1]);
            } else {	//c<t
                ret.push_back(m1[t-1]>m2[h]?m1[t-1]:m2[h]);
            }
        }
        return ret;
    }
};