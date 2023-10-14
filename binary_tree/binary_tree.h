#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct TNode {
    int data;
   struct TNode* left;
   struct TNode* right;
};
typedef struct TNode TNode;

TNode* createNode(int data) ;
TNode* insert( TNode* root, int data);
TNode* delete(TNode* root, int data);
#endif