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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* p1=NULL;
        TreeNode* p2=NULL;
        TreeNode* p1t=NULL;
        if(pRootOfTree == NULL){
            return NULL;
        }
        if(pRootOfTree->left==NULL && pRootOfTree->right==NULL){
            return pRootOfTree;
        }
        p1 = Convert(pRootOfTree->left);
        p1t = p1;
        while(p1t && p1t->right){
            p1t = p1t->right;
        }
        p2 = Convert(pRootOfTree->right);
        pRootOfTree->left = p1t;
        pRootOfTree->right = p2;
        if(p1){
            p1t->right = pRootOfTree;
        }
        if(p2){
            p2->left = pRootOfTree;
        }
        
        if(p1){
            return p1;
        } else {
            return pRootOfTree;
        }
    }
};