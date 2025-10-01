#ifndef COMPLETE_BINARY_TREE_H
#define COMPLETE_BINARY_TREE_H

#include "tree_node.h"

class CompleteBinaryTree {
private:
    TreeNode* root;

    bool search(TreeNode* node, int value);
    TreeNode* findParent(TreeNode* node, TreeNode* target);
    TreeNode* findLastNode();
    void preOrder(TreeNode* node);
    void inOrder(TreeNode* node);
    void postOrder(TreeNode* node);
    void clearTree(TreeNode* node);

public:
    CompleteBinaryTree();
    ~CompleteBinaryTree();

    void addNode(int value);
    bool searchNode(int value);
    void removeNode(int value);

    void addTree(CompleteBinaryTree& otherTree);

    void levelOrder();
    void depthFirstTraversals();

    bool isEmpty();
    void clear();
};

#endif
