/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		return buildTree(&pre, &vin, 0, 0, pre.size());
	}

	TreeNode* buildTree(vector<int>* str1, vector<int>* str2, int head1, int head2, int len) {
		if (len == 0) {
			return NULL;
		}
		TreeNode* pTree = new TreeNode( (*str1)[head1]);
		int i;
		for (i = 0; i<len; i++) {
			if ((*str2)[head2+i] ==  (*str1)[head1]){
				break;
			}
		}
		pTree->left = buildTree(str1, str2, head1+1, head2, i);
		pTree->right = buildTree(str1, str2, head1+1 + i, head2+1 + i, len - 1 - i);
		return pTree;
	}
};