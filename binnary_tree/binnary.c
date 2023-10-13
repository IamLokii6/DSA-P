#include <stdio.h>
#include <stdlib.h>
#include "binnary.h"

TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode)
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

TreeNode *insert(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

TreeNode* delete(TreeNode* root,int data){
    if(root==NULL)
    return root;

    if(root->data > data){
        root->left = delete(root->left, data);
        return root;
    }
    else if(root->data < data){
        root->right = delete(root->right, data);
        return root;
    }

    if (root->left == NULL) {
        TreeNode* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        TreeNode* temp = root->left;
        free(root);
        return temp;
    }
    
    else{
        TreeNode* succParent= root;

        TreeNode* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        root->data = succ->data;
 
        free(succ);
        return root;
    }

}