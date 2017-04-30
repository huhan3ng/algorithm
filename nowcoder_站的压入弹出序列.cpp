#include<stack>
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int i=0,j=0;
        stack<int> a;
        while(j<popV.size()){	//每个元素至多压栈一次
            if(!a.empty() && a.top()==popV[j]){
                a.pop();
                j++;
            } else {
                if(i>=popV.size()){
                    break;
                }
                a.push(pushV[i++]);
            }
        }
        if(a.empty()){
            return true;
        } else {
            return false;
        }
        
    }
};