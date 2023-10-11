#include <stdio.h>;
#include "tree_traversal.h"

// inorder traversal
void inorderTraversal(node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d->", root->data);
    inorderTraversal(root->right);
}
