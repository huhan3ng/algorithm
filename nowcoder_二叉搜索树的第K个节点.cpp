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
    int i=0;
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL || i>k){
            return NULL;
        }
        TreeNode* retL= KthNode(pRoot->left, k);	//先在左字数找
        if(retL){
            return retL;
        }
        if((++i) == k){
            return pRoot;
        }
        return KthNode(pRoot->right, k);	//再在有字数找8568k是什么鬼
    }
};