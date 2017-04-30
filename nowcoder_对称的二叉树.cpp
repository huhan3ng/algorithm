/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL){
            return true;
        }
    	return subSymmetric(pRoot->left, pRoot->right);
    }
	bool subSymmetric(TreeNode* pL, TreeNode* pR){
        if(pL==NULL && pR==NULL){
            return true;
        } else if(pL==NULL || pR==NULL){
            return false;
        } else {
            return subSymmetric(pL->left, pR->right) && subSymmetric(pL->right, pR->left) && (pL->val == pR->val);
        }
    }
};