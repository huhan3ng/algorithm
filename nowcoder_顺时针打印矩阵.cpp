class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int up=0,down=matrix.size()-1,left=0,right=matrix[0].size()-1;
        int i=left,j=up,k=0, lasti=i, lastj=j-1,di=0,dj=0;
        vector<int> ret(matrix.size()*matrix[0].size(), 0);
        while(right>=left && down>=up){
            cout<< matrix[i][j]<<endl;
            ret[k++] = matrix[i][j];
            //更新坐标
            di = i-lasti;
            dj = j-lastj;
            lasti = i;
            lastj = j;
            if((j+dj)>right || (i+di)>down || (j+dj)<left || (i+di)<up){
            	//拐弯表示已经遍历了一行或一列了
                if((j+dj)>right){
                    up++;
                } else if((j+dj)<left){
                    down--;
                } else if((i+di)>down){
                    right--;
                } else if((i+di)<up){
                    left++;
                }
                j = j-di;
                i = i+dj;
            } else {
                i = i+di;
                j = j+dj;
            }
        }
        return ret;
    }
};