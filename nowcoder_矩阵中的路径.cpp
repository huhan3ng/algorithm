class Solution {
    int mRows, mCols;
    char* mMatrix;
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        bool ret1;
        mRows=rows;
        mCols=cols;
        mMatrix=matrix;
        vector<vector<bool>> flag(rows, vector<bool>(cols, false));
    	for(int x=0;x<rows;x++){
            for(int y=0;y<cols;y++){
                ret1=subMatch(str, x, y, flag);
                if(ret1){
                    return ret1;
                }
            }
        }
        return false;
    }

	bool isValid(vector<vector<bool>> &flag, int x, int y){
        if(x<0 || x>=mRows || y<0 || y>=mCols || flag[x][y]){
            return false;
        } else {
            return true;
        }
    }
    
    bool subMatch(char* str, int x, int y, vector<vector<bool>> &flag){
        if(!*str){
            return true;
        } else {
            if(!isValid(flag, x, y) || mMatrix[x*mCols+y]!=*str){
                return false;
            } else {
                flag[x][y]=true;
	            bool ret = subMatch(str+1, x+1, y, flag) || subMatch(str+1, x-1, y, flag) || subMatch(str+1, x, y+1, flag) || subMatch(str+1, x, y-1, flag);
				flag[x][y]=false;
                return ret;
            }
        }
    }
};