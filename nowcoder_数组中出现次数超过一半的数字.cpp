class Solution {
    vector<int> larger;
    vector<int> smaller;
    vector<int> equal;
    int min;
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	min = (numbers.size())/2+1;
        return submore(numbers);
    }
    
    int submore(vector<int> numbers){
		if(numbers.size()<min){
            return false;
        } else {
            int a = numbers[numbers.size()/2];
            larger.clear();
            smaller.clear();
            equal.clear();
            for(int i=0;i<numbers.size();i++){
                if(numbers[i]==a){
                    equal.push_back(numbers[i]);
                } else if(numbers[i]<a){
                    smaller.push_back(numbers[i]);
                } else {
                    larger.push_back(numbers[i]);
                }
            }
            if(equal.size() >= min){
                return equal.back();
            } 
            if(smaller.size()>=min){
                return submore(vector<int>(smaller.begin(), smaller.end()));
            } 
            if(larger.size()>=min){
                return submore(vector<int>(larger.begin(), larger.end()));
            }
            return false;
        }
    }
};