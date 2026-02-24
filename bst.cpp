#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode *left, *right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
    BSTNode* root;
    BSTNode* insert(BSTNode* node, int val) {
        if (!node) return new BSTNode(val);
        if (val < node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }
public:
    BST() : root(nullptr) {}
    void insert(int val) { root = insert(root, val); }

    // Search: Average O(log n), Worst O(n)
    bool search(BSTNode* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        return (val < node->data) ? search(node->left, val) : search(node->right, val);
    }
    bool search(int val) { return search(root, val); }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    cout << "BST Search 70: " << (tree.search(70) ? "Found" : "Not Found") << endl;
    cout << "BST Search 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;
    return 0;
}