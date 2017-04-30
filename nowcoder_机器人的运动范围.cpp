class Solution {
    int mRows,mCols,mThreshold, ret=0;
public:
    int movingCount(int threshold, int rows, int cols)
    {
        mRows=rows;
        mCols=cols;
        mThreshold=threshold;
        vector<vector<bool>> flag(rows, vector<bool>(cols, false));
        subMove(flag, 0, 0);
        return ret;
    }
    
    void subMove(vector<vector<bool>> &flag, int x, int y){
        if(x<0||x>=mRows||y<0||y>=mCols||flag[x][y] || !checkSum(x,y)){
            return;
        } else {
            ret++;
            flag[x][y]=true;
            subMove(flag, x+1, y);
            subMove(flag, x-1, y);
            subMove(flag, x, y+1);
            subMove(flag, x, y-1);
            return;
        }
    }
    
    bool checkSum(int x, int y){
        int sum=0;
        while(x){
            sum+=x%10;
            x=x/10;
        }
        while(y){
            sum+=y%10;
            y=y/10;
        }
        if(sum>mThreshold){
            return false;
        } else {
            return true;
        }
    }
};