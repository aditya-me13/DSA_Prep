// Problem Link: https://www.naukri.com/code360/problems/convert-binary-tree-to-mirror-tree_873140?topList=top-google-coding-interview-questions&leftPanelTab=1&leftPanelTabValue=PROBLEM

// #include <bits/stdc++.h> 

/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
BinaryTreeNode<int>* helper(BinaryTreeNode<int> *root){
    if(!root) return nullptr;
    BinaryTreeNode<int>* left = root->left;
    BinaryTreeNode<int>* right = root->right;
    root->left = helper(right);
    root->right = helper(left);
}

void mirrorTree(BinaryTreeNode<int> *root) {
    root = helper(root);
}