/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if(pRoot1==NULL || pRoot2==NULL){
            return false;
        } else if(pRoot1->val == pRoot2->val){
            if(pRoot2->left==NULL && pRoot2->right==NULL){
                return true;
            } else if(pRoot2->left==NULL){
                return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2) || HasSubtree(pRoot1->right, pRoot2->right);
            } else if(pRoot2->right==NULL){
                return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2) || HasSubtree(pRoot1->left, pRoot2->left);    
            } else {
            	return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2) ||
                	(HasSubtree(pRoot1->left, pRoot2->left) && HasSubtree(pRoot1->right, pRoot2->right));
            }
        } else {
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }
    }
};