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

vector<int> inorder(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    stack<TreeNode *> inorder;
    while (root)
    {
        inorder.push(root);
        root = root->left;
    }

    while (!inorder.empty())
    {
        TreeNode *tmpN = inorder.top();
        inorder.pop();
        res.push_back(tmpN->val);
        // cout<<tmpN->val<<" ";
        TreeNode *right = tmpN->right;
        while (right)
        {
            inorder.push(right);
            right = right->left;
        }
    }
    return res;
}

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
    root = Insert(root, 50);
    root = Insert(root, 10);
    root = Insert(root, 100);
    root = Insert(root, 5);
    root = Insert(root, 20);
    root = Insert(root, 60);
    root = Insert(root, 150);
    root = Insert(root, 2);
    root = Insert(root, 55);
    root = Insert(root, 52);
    // Print Nodes in Inorder.
    cout << "Inorder: ";
    vector<int> res = inorder(root);
    for (auto i : res)
        cout << i << " ";
}