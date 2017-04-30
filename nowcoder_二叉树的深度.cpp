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
    int TreeDepth(TreeNode* pRoot)
    {
		if(pRoot){
            int ldp=TreeDepth(pRoot->left);
            int rdp=TreeDepth(pRoot->right);
            return 1+(ldp>rdp?ldp:rdp);
        }else {
            return 0;
        }
    }
};