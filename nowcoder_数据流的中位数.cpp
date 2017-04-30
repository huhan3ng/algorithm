class Solution {
public:
    vector<int> s;
    void Insert(int num)
    {
        int i=0;
        while(i<s.size() && num<s[i]){
            i++;
        }
        s.insert(s.begin()+i, num);
    }

    double GetMedian()	//前提插入的时候排好序了
    { 
    	if(s.size()%2==1){
            return s[s.size()/2];
        } else {
            if(s.empty()){
                return 0;
            }
            return ((double)(s[s.size()/2-1]+s[s.size()/2]))/2;
        }
    }

};