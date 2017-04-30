class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {		//排序数组，从小到大?
        int h=0,t=data.size(),c;
        while((t-h)>0){
            c=(h+t)/2;
            if(k>data[c]){
                h=c+1;
            } else if(k<data[c]){
                t=c;
            } else {
             	break;   
            }
        }
        if((t-h)==0){	//没找到
            return 0;
        } else {
            int i=1,j=0;
            while(k==data[c+i]){
                i++;
                j++;
            }
            i=1;
            while(k==data[c-i]){
                i++;
                j++;
            }
            return j+1;
        }
    }
};