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
    vector<vector<int> > Print(TreeNode* pRoot) {
        int i=0,j=0;	//层数
        vector<vector<int>> ret;
        vector<TreeNode*> retP;
        if(pRoot==NULL){
            return ret;
        }
        ret.push_back(vector<int>(1, pRoot->val));
        retP.push_back(pRoot);
        while(retP.size()){
            vector<int> b;
            vector<TreeNode*> pB;
            if((i%2)==0){
               	 for(j=retP.size()-1;j>=0;j--){
                     if(retP[j]->right){
                         pB.push_back(retP[j]->right);
                         b.push_back(retP[j]->right->val);
                     }
                     if(retP[j]->left){
                      	pB.push_back(retP[j]->left);
                       	b.push_back(retP[j]->left->val);
                     }
                 }
            } else {
               	 for(j=retP.size()-1;j>=0;j--){
                     if(retP[j]->left){
                      	pB.push_back(retP[j]->left);
                        b.push_back(retP[j]->left->val);
                     }
                     if(retP[j]->right){
						pB.push_back(retP[j]->right);
                        b.push_back(retP[j]->right->val);
                     }
                 }
            }
            ret.push_back(b);
            retP.clear();
            retP.assign(pB.begin(), pB.end());
            i++;
        }
        ret.pop_back();
        return ret;
    }
};