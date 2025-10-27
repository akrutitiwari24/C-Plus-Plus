/**
 * @file
 * @brief Implementation of Binary Search Tree operations.
 * @details
 * Includes insertion, search, and inorder traversal.
 */

#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* insert(Node* root, int val) {
        if (!root) return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }

    bool search(Node* root, int val) {
        if (!root) return false;
        if (root->data == val) return true;
        if (val < root->data)
            return search(root->left, val);
        else
            return search(root->right, val);
    }
};

int main() {
    BinarySearchTree bst;
    Node* root = nullptr;
    root = bst.insert(root, 5);
    bst.insert(root, 3);
    bst.insert(root, 7);
    bst.insert(root, 4);

    std::cout << "Inorder traversal: ";
    bst.inorder(root);
    std::cout << "\nSearch 4: " << (bst.search(root, 4) ? "Found" : "Not Found") << std::endl;

    return 0;
}
