/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//#include<stdint.h>
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        struct TreeNode* tmp = NULL;
        if(pRoot){
            //交换左右节点
            //pRoot->right = (struct TreeNode*)(((uintptr_t)pRoot->left)^((uintptr_t)pRoot->right));
            //pRoot->left = (struct TreeNode*)(((uintptr_t)pRoot->left)^((uintptr_t)pRoot->right));
            //pRoot->right = (struct TreeNode*)(((uintptr_t)pRoot->left)^((uintptr_t)pRoot->right));
            tmp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = tmp;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
};