#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

class BinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(NULL), right(NULL) {}
    };

    Node* root;

public:
    BinaryTree();
    void insert(int value);
    void remove(int value);
    void clear();
    int size();
    void inorder();
    void preorder();
    void postorder();

private:
    Node* insertRecursive(Node* root, int value);
    Node* removeRecursive(Node* root, int value);
    Node* minValueNode(Node* node);
    void clearRecursive(Node* root);
    int sizeRecursive(Node* root);
    void inorderRecursive(Node* root);
    void preorderRecursive(Node* root);
    void postorderRecursive(Node* root);
};

#endif // BINARYTREE_H