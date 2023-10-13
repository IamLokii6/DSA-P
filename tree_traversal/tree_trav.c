#include<stdio.h>
#include "tree_trav.h"

void inorderTraversal(TreeNode* root){
    if(root == NULL)
    return;
    inorderTraversal(root->left);
    printf("%d->", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode* root){
    if(root == NULL)
    return;
    printf("%d->", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root){
    if(root==NULL)
    return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->data);
}

