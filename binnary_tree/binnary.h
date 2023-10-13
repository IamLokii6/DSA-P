#ifndef BINNARY_H
#define BINNARY_H

struct TreeNode {
    int data;
   struct TreeNode* left;
   struct TreeNode* right;
};
typedef struct TreeNode TreeNode;

TreeNode* createNode(int data) ;
TreeNode* insert( TreeNode* root, int data);
TreeNode* delete(TreeNode* root, int data);
#endif