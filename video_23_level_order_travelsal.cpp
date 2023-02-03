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

void printGivenLevel(TreeNode *root, int level, vector<int> &levelH)
{
    if (root == NULL)
        return;
    if (level == 0)
    {
        levelH.push_back(root->val);
    }
    else if (level > 0)
    {
        printGivenLevel(root->left, level - 1, levelH);
        printGivenLevel(root->right, level - 1, levelH);
    }
}

vector<int> levelOrderIterative(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<int> result;
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        root = Q.front();
        Q.pop();
        result.push_back(root->val);
        if (root->left != NULL)
            Q.push(root->left);
        if (root->right != NULL)
            Q.push(root->right);
    }
    return result;
}

vector<vector<int>> levelOrderLineByLineIterative(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> result;
    vector<int> currLevel;
    queue<TreeNode *> Q;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        root = Q.front();
        Q.pop();
        if (root == NULL)
        {
            result.push_back(currLevel);
            currLevel.clear();
            if(!Q.empty()){
                Q.push(NULL);
            }
        }
        else
        {
            currLevel.push_back(root->val);
            if (root->left != NULL)
                Q.push(root->left);
            if (root->right != NULL)
                Q.push(root->right);
        }
    }
    return result;
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> levelOrder;
    int H = height(root);
    for (int h = 0; h <= H; h++)
    {
        vector<int> levelH;
        printGivenLevel(root, h, levelH);
        levelOrder.push_back(levelH);
    }
    return levelOrder;
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
    cout << "Level: " << endl;
    vector<vector<int>> res = levelOrderLineByLineIterative(root);
    // vector<int> res = levelOrderIterative(root);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    // for (auto i : res)
    //     cout << i << " ";
}