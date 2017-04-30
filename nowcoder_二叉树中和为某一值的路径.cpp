/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include<vector>
class Solution {
    vector<vector<int>> ret;
    vector<int> stack;
    void subFind(TreeNode* root,int expectNumber){
        stack.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(expectNumber == root->val){
                ret.push_back(vector<int>(stack.begin(), stack.end()));
            }
        } else {
            if(root->left !=NULL){
            	subFind(root->left, expectNumber-root->val);
        	}
            if(root->right !=NULL){
            	subFind(root->right, expectNumber-root->val);
        	}
        }
       	stack.pop_back();
    }
    
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL){
            return ret;
        }
		subFind(root, expectNumber);
        return ret;
    }
    
};