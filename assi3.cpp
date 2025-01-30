#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); 
    }

    char side;
    cout << "Insert " << val << " to the left or right of " << root->data << "? (l/r): ";
    cin >> side;

    if (side == 'l' || side == 'L') {
        
        if (root->left == nullptr) {
            root->left = new Node(val);
        } else {
            root->left = insert(root->left, val);
        }
    } else if (side == 'r' || side == 'R') {
        
        if (root->right == nullptr) {
            root->right = new Node(val);
        } else {
            root->right = insert(root->right, val);
        }
    } else {
        cout << "Invalid choice! Please choose 'l' for left or 'r' for right." << endl;
    }
    
    return root;
}


void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    inorderTraversal(root->left); 
    cout << root->data << " "; 
    inorderTraversal(root->right); 
}

void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " "; 
    preorderTraversal(root->left); 
   
    preorderTraversal(root->right); 
}

void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    postorderTraversal(root->left); 
   
    postorderTraversal(root->right); 
    cout << root->data << " "; 
}


int main() {
    Node* root = nullptr;
    int val;
    char more;

    
    cout << "Enter the root node value: ";
    cin >> val;
    root = new Node(val);

    do {
        cout << "Enter value to insert: ";
        cin >> val;

        
        root = insert(root, val);

        cout << "Do you want to insert another node? (y/n): ";
        cin >> more;

    } while (more == 'y' || more == 'Y');

    
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}