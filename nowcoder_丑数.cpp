class Solution {
    vector<int> v;
public:
    Solution(){
        v.push_back(1);
    }
    int GetUglyNumber_Solution(int index) {
    	int a,b,c;
        while(index>v.size()){
            a=getMinLarger(v.back()/2)*2;
            b=getMinLarger(v.back()/3)*3;
            c=getMinLarger(v.back()/5)*5;
            if(a<=b && a<=c){
                v.push_back(a);
            } else if(b<=a && b<=c){
                v.push_back(b);
            } else if(c<=a && c<=b){
                v.push_back(c);
            }
        }
        return v[index-1];
    }
    int getMinLarger(int val){
        int i=v.size()-1;
        while(i>=0 && v[i]>val){
            i--;
        }
        return v[i+1];
    }
};