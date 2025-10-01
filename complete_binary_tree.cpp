#include "complete_binary_tree.h"
#include <iostream>
#include <queue>
using namespace std;

TreeNode::TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}

CompleteBinaryTree::CompleteBinaryTree() : root(nullptr) {}

CompleteBinaryTree::~CompleteBinaryTree() {
    clear();
}

bool CompleteBinaryTree::search(TreeNode* node, int value) {
    if (node == nullptr) return false;
    if (node->data == value) return true;
    return search(node->left, value) || search(node->right, value);
}

TreeNode* CompleteBinaryTree::findParent(TreeNode* node, TreeNode* target) {
    if (node == nullptr || node == target) return nullptr;

    if (node->left == target || node->right == target) {
        return node;
    }

    TreeNode* leftResult = findParent(node->left, target);
    if (leftResult != nullptr) return leftResult;

    return findParent(node->right, target);
}

TreeNode* CompleteBinaryTree::findLastNode() {
    if (root == nullptr) return nullptr;

    queue<TreeNode*> q;
    q.push(root);
    TreeNode* last = nullptr;

    while (!q.empty()) {
        last = q.front();
        q.pop();

        if (last->left != nullptr) q.push(last->left);
        if (last->right != nullptr) q.push(last->right);
    }
    return last;
}

void CompleteBinaryTree::addNode(int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current->left == nullptr) {
            current->left = new TreeNode(value);
            return;
        } else {
            q.push(current->left);
        }

        if (current->right == nullptr) {
            current->right = new TreeNode(value);
            return;
        } else {
            q.push(current->right);
        }
    }
}

bool CompleteBinaryTree::searchNode(int value) {
    return search(root, value);
}

void CompleteBinaryTree::removeNode(int value) {
    if (root == nullptr) return;

    TreeNode* toDelete = nullptr;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current->data == value) {
            toDelete = current;
            break;
        }

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }

    if (toDelete == nullptr) return;

    TreeNode* lastNode = findLastNode();
    toDelete->data = lastNode->data;

    TreeNode* parent = findParent(root, lastNode);
    if (parent != nullptr) {
        if (parent->left == lastNode) parent->left = nullptr;
        else parent->right = nullptr;
    }
    delete lastNode;
}

void CompleteBinaryTree::preOrder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
void CompleteBinaryTree::inOrder(TreeNode* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void CompleteBinaryTree::postOrder(TreeNode* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

void CompleteBinaryTree::depthFirstTraversals() {
    cout << "Pre-order: ";
    preOrder(root);
    cout << endl;

    cout << "In-order: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order: ";
    postOrder(root);
    cout << endl;
}

void CompleteBinaryTree::levelOrder() {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    cout << "Обход в ширину: ";
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
    cout << endl;
}

void CompleteBinaryTree::addTree(CompleteBinaryTree& otherTree) {
    if (otherTree.root == nullptr) return;

    queue<TreeNode*> q;
    q.push(otherTree.root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        addNode(current->data);

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

bool CompleteBinaryTree::isEmpty() {
    return root == nullptr;
}

void CompleteBinaryTree::clearTree(TreeNode* node) {
    if (node == nullptr) return;
    clearTree(node->left);
    clearTree(node->right);
    delete node;
}

void CompleteBinaryTree::clear() {
    clearTree(root);
    root = nullptr;
}
