class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* curr, TreeNode* p, TreeNode* q) {
		if(!curr || curr==p || curr==q) return curr;
		TreeNode* l=lowestCommonAncestor(curr->left,p,q);
		TreeNode* r=lowestCommonAncestor(curr->right,p,q);
		if(!l) return r;
		else if(!r) return l;
		else return curr;
	}
};
