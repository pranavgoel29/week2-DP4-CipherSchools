#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *Insert(TreeNode *root, int data)
{
    if (root == NULL)
    {
        root = new TreeNode();
        root->val = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->val)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

int diameter(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    return max(lh + rh + 1, max(ld, rd));
}

int main()
{

    /*
                50
               /  \
             10   100
            / \   / \
           5  20 60 150
          /      /
          2      55
                 /
                52
            */

    TreeNode *root = NULL;
    // root = Insert(root, 50);
    // root = Insert(root, 10);
    // root = Insert(root, 100);
    // root = Insert(root, 5);
    // root = Insert(root, 20);
    // root = Insert(root, 60);
    // root = Insert(root, 150);
    // root = Insert(root, 2);
    // root = Insert(root, 55);
    // root = Insert(root, 52);
    root = Insert(root, 1);
    root = Insert(root, 2);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 5);
    // Print Nodes in Inorder.
    cout << "Diameter: ";
   
    cout<<diameter(root)<<endl;
    
}