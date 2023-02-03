#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        val = val;
        left = NULL;
        right = NULL;
    }
};
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root == NULL)
        return NULL;
    if(p->val == root->val || q->val == root->val)
        return root;
    Node* a = lowestCommonAncestor(root->left, p, q);
    Node* b = lowestCommonAncestor(root->right, p, q);

    if( a && b )
        return root;
    return a ? a : b;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(6);

    Node* node = lowestCommonAncestor(root, 0, 0);
    cout<<node<<endl;
    return 0;
}
