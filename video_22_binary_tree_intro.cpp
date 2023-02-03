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

void inorder(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

vector<int> inorder(TreeNode *root)
{
    vector<int> result;
    inorder(root, result);
    return result;
}

vector<int> preorder(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> back;
    auto cur = root;
    while (cur || !back.empty())
    {
        if (cur)
        {
            res.push_back(cur->val);
            if (cur->right)
                back.push(cur->right);
            cur = cur->left;
        }
        else
        {
            cur = back.top();
            back.pop();
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

    // root left right
    // vector<int> res = preorder(root);

    vector<int> res = inorder(root);
    for (auto i : res)
        cout << i << " ";
}