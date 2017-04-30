class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	vector<vector<int>> tmp(array.size()+1, vector<int>(array.size()+1, 0));
        int max = array[0];
        int n=array.size();
        for(int len=1;len<=n;len++){
            for(int i=0;i<=(n-len);i++){
                tmp[i][i+len-1] = array[i]+tmp[i+1][i+len-1];
                if(tmp[i][i+len-1]>max){
                    max = tmp[i][i+len-1];
                }
            }
        }
        return max;
    }
};