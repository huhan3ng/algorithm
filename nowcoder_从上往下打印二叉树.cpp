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
    vector<TreeNode*> a;
    vector<int> b;
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		int i=0;
        TreeNode* tmp=NULL;
        if(!root){
            return b;
        } else {
            a.push_back(root);
            while(i<a.size()){
                tmp = a[i++];
                cout<<tmp->val<<endl;
                b.push_back(tmp->val);
                if(tmp->left){
                    a.push_back(tmp->left);
                }
                if(tmp->right){
                    a.push_back(tmp->right);
                }
            }
        }
        return b;
    }
};