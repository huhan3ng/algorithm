class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        vector<int> count(length, 0);
        int i,j=0;
        for(i=0;i<length;i++){
            if(numbers[i]>=length || numbers[i]<0){
                return false;
            }
            count[numbers[i]]++;
            if(count[numbers[i]]>1){
                *(duplication+j)= numbers[i];
                j++;
            }
        }
        if(j==0){
            return false;
        } else {
            return true;
        }
    }
};