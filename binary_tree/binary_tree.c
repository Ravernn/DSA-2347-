#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

// Creating and returing a new node
TNode *createNode(int data)
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    if (newNode)
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

TNode *insert(TNode *root, int data)
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
TNode* delete(TNode* root,int data){
    if(root==NULL)
    return root;

    // Recursive calls for ancestors of node to be deleted
    if(root->data > data){
        root->left = delete(root->left, data);
        return root;
    }
    else if(root->data < data){
        root->right = delete(root->right, data);
        return root;
    }

    // We reach here when root node is to be deleted.

    // If one of the children is empty
    if (root->left == NULL) {
        TNode* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        TNode* temp = root->left;
        free(root);
        return temp;
    }
    
    // If both childs exist
    else{
        TNode* sucParent= root;

        // Find successor
        TNode* suc = root->right;
        while (suc->left != NULL) {
            sucParent = suc;
            suc = suc->left;
        }

        if (sucParent != root)
            sucParent->left = suc->right;
        else
            sucParent->right = suc->right;
 
        // Copy Successors Data to root
        root->data = suc->data;
 
        // Delete Successor, returns the root
        free(suc);
        return root;
    }

}
