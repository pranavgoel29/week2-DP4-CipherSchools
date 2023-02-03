class Solution {
public:
    int ans;
    TreeNode* f(TreeNode* root,int &k)
    {
        if(root==NULL)
            return NULL;
     TreeNode* l=f(root->left,k);
        k--;
        if(k==0)
        {
            ans=root->val;
            return root;
        }
        TreeNode* r=f(root->right,k);
        return root;
    }
    int kthSmallest(TreeNode* root, int k) {
        ans=root->val;
        TreeNode* r=f(root,k);
        return ans;
    }
};
