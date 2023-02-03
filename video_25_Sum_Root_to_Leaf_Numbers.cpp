class Solution {
public:
void solve(TreeNode* root, int& sum,int num){
     if(!root) return;
    num = num*10 + root->val;
    if(root->left==NULL && root->right==NULL) {         //base case
     sum += num;
     return;
    }  
   
    //choice diagram
    
     solve(root->left, sum,num);
     
     solve(root->right,sum,num);

 
}
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int num=0;
        solve(root,sum,num);
        return sum;
    }
};
