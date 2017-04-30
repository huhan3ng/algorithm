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
    char* Serialize(TreeNode *root) {
        string sRet;
        subSeri(sRet, root);
        char *ret = new char[sRet.length()];
        strcpy(ret, sRet.c_str());
        return ret;
    }
    TreeNode* Deserialize(char *str) {
		return subDeSeri(str);
    }
    
    void subSeri(string &sRet, TreeNode *root){
        if(root==NULL){
            sRet.push_back('#');
            return;
        }
        sRet.push_back(root->val);
        subSeri(sRet, root->left);
        subSeri(sRet, root->right);
    }
    
    TreeNode* subDeSeri(char* &str){
        if((*str)!='#'){
	        TreeNode* root=new TreeNode((unsigned char)*str);	//val不能大于255.....
            str++;
            root->left=subDeSeri(str);
            root->right=subDeSeri(str);
            return root;
        } else {
            str++;
            return NULL;
        }
    }
    
};