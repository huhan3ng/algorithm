class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(TreeDepth(pRoot)>=0){
            return true;
        } else {
            return false;
        }
    }
    
    int TreeDepth(TreeNode* pRoot)
    {
		if(pRoot){
            int ldp=TreeDepth(pRoot->left);
            int rdp=TreeDepth(pRoot->right);
            if(ldp==-1 || rdp==-1 || (ldp>=rdp && (ldp-rdp)>1) || (ldp<=rdp && (rdp-ldp)>1)){
                return -1;
            }
            return 1+(ldp>rdp?ldp:rdp);
        }else {
            return 0;
        }
    }
};