class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {	//是否为定长？
        vector<int> a(14, 0);
        int empty=0, min=14, max=0, uniqueNum=0, empty2=0;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]==0){
                empty++;
            } else {
                a[numbers[i]] = 1;
                if(numbers[i]<min){
                    min = numbers[i];
                }
                if(numbers[i]>max){
                    max = numbers[i];
                }
            }
        }
        empty2=empty;
        for(int i=min;i<=max;i++){
            if(a[i]==0){
                empty--;
            } else {
                uniqueNum++;
            }
        }
        if((empty2+uniqueNum)<5){
         	return false;   
        }
        if(empty<0){
            return false;
        } else {
            return true;
        }
        
    }
};