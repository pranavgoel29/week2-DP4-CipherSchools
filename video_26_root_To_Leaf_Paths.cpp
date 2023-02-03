#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool isLeaf(Node* root){
    return (root!=NULL && !root->left && !root->right);
}
void printPaths(vector<int> &path){
    for(auto i: path)
        cout<<i<<' ';
    cout<<endl;
}
void printPaths(Node* root, vector<int> &path){
    if(root == NULL)
        return;
    path.push_back(root->data);
    if(isLeaf(root)){
        printPaths(path);
        return;
    }
    else {
        printPaths(root->left, path);
        printPaths(root->right, path);
    }
    path.pop_back();
}
void rootToLeafPaths(Node* root){
    if(root == NULL)
        return;
    vector<int> path;
    printPaths(root, path);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(6);

    rootToLeafPaths(root);
    
    return 0;
}
