class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int tmp=0,i=0,j=0,c=0;
        for(i=0;i< array.size();i++){
            if(array[i]%2==1){
                j = i;
                tmp = array[j];
                while(j>c){
                    array[j] = array[j-1];
                    j--;
                }
                array[c] = tmp;
                c++;
            }
        }
    }
};