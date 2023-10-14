#include<stdio.h>
#include "tree_traversal.h"


//INORDER TRAVERSAL
void inorderTraversal(TNode* root){
    if(root == NULL)
    return;
    inorderTraversal(root->left);
    printf("%d->", root->data);
    inorderTraversal(root->right);
}

//POSTORDER TRAVERSAL
void postorderTraversal(TNode* root){
    if(root==NULL)
    return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->data);
}

//  PREORDER TRAVERSAL
void preorderTraversal(TNode* root){
    if(root == NULL)
    return;
    printf("%d->", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

