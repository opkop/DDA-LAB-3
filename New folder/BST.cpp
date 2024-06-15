#include <iostream>
using namespace std;

// Structure for a node of the BST
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a key into BST
Node* insert(Node* root, int key, int& steps) {
    if (root == nullptr) {
        return createNode(key);
    }

    steps++; // Increment step for each comparison
    if (key < root->key) {
        root->left = insert(root->left, key, steps);
    } else if (key > root->key) {
        root->right = insert(root->right, key, steps);
    }
    return root;
}

// Function to perform inorder traversal of BST
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int n;
    cout << "Enter the number of keys to insert: ";
    cin >> n;
    cout << "Enter the keys to insert:\n";
    int key;
    int steps = 0; // Counter for steps
    for (int i = 0; i < n; ++i) {
        cin >> key;
        root = insert(root, key, steps);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    cout << "Total steps taken: " << steps << endl;

    return 0;
}
