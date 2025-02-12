#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

node* insert(node* root, int val) {
    if (root == nullptr) {
        return new node(val); 
    }

    char side;
    cout << "Insert " << val << " to the left or right of " << root->data << "? (l/r): ";
    cin >> side;

    if (side == 'l' || side == 'L') {
        
        if (root->left == nullptr) {
            root->left = new node(val);
        } else {
            root->left = insert(root->left, val);
        }
    } else if (side == 'r' || side == 'R') {
        
        if (root->right == nullptr) {
            root->right = new node(val);
        } else {
            root->right = insert(root->right, val);
        }
    } else {
        cout << "Invalid choice! Please choose 'l' for left or 'r' for right." << endl;
    }
    
    return root;
}

void inorderTraversal(node* root) {
    if (root == nullptr) {
        return;
    }
    
    inorderTraversal(root->left); 
    cout << root->data << " "; 
    inorderTraversal(root->right); 
}

void preorderTraversal(node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " "; 
    preorderTraversal(root->left); 
    preorderTraversal(root->right); 
}

void postorderTraversal(node* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left); 
    postorderTraversal(root->right); 
    cout << root->data << " "; 
}

void levelOrderTraversal(node* root) {
    if (root == nullptr) {
        return;
    }

    queue<node*> q;
    q.push(root);  

    while (!q.empty()) {
        node* current = q.front();
        q.pop(); 
        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

vector<int> inOrder(node* root) {
    vector<int> ans;
    stack<node*> s;
    node* curr = root;

    while (curr != nullptr || !s.empty()) {
        
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        ans.push_back(curr->data);
        curr = curr->right;
    }
    
    return ans;
}

vector<int> postOrder(node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    stack<node*> stk1, stk2;
    stk1.push(root);
    node* curr;

    while (!stk1.empty()) {
        curr = stk1.top();
        stk1.pop();
        stk2.push(curr);

        if (curr->left) {
            stk1.push(curr->left);
        }
        if (curr->right) {
            stk1.push(curr->right);
        }
    }

    while (!stk2.empty()) {
        curr = stk2.top();
        stk2.pop();
        result.push_back(curr->data);
    }

    return result;
}

void iterativePreorder(node* root) {
    if (root == NULL)
        return;

    stack<node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        node* node = nodeStack.top();
        cout << node->data << " ";
        nodeStack.pop();

        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}

bool checkequal(node* r1, node* r2){
    if (r1 == nullptr && r2 == nullptr) {
        return true;
    } else if (r1 == nullptr || r2 == nullptr) {
        return false;
    } else if (r1->data == r2->data) {
        bool leftEqual = checkequal(r1->left, r2->left);
        bool rightEqual = checkequal(r1->right, r2->right);
        return leftEqual && rightEqual;
    }
    return false;
}

node* Createmirror(node* r1) {
    if (r1 == nullptr) {
        return nullptr;
    } else {
        node* x = new node(r1->data);
        x->right = Createmirror(r1->left);
        x->left = Createmirror(r1->right);
        return x;
    }
}

node* Createclone(node* r1) {
    if (r1 == nullptr) {
        return nullptr;
    } else {
        node* x = new node(r1->data);
        x->right = Createclone(r1->right);
        x->left = Createclone(r1->left);
        return x;
    }
}

int height(node* root) {
    if (root == nullptr)
        return 0;

    int lHeight = height(root->left);  
    int rHeight = height(root->right);  

    return max(lHeight, rHeight) + 1;  
}


void printArray(const vector<int>& arr) {
    for (int data : arr) {
        cout << data << " ";
    }
    cout << endl;
}

int main() {
    node* root = nullptr;
    int val;
    char more;

    cout << "Enter the root node value: ";
    cin >> val;
    root = new node(val);

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

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Levelorder traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "Inorder traversal (non-recursive): ";
    vector<int> result = inOrder(root);
    printArray(result);

    cout << "Preorder traversal (non-recursive): ";
    iterativePreorder(root);
    cout << endl;

    cout << "Postorder traversal (non-recursive): ";
    vector<int> result2 = postOrder(root);
    printArray(result2);

    node* clonedRoot = Createclone(root);
    cout << "Cloned tree Inorder traversal: ";
    inorderTraversal(clonedRoot);
    cout << endl;

    node* mirroredRoot = Createmirror(root);
    cout << "Mirrored tree Inorder traversal: ";
    inorderTraversal(mirroredRoot);
    cout << endl;

    if (checkequal(root, clonedRoot)) {
        cout << "The original tree and cloned tree are equal." << endl;
    } else {
        cout << "The original tree and cloned tree are not equal." << endl;
    }

    // if (checkequal(root, mirroredRoot)) {
    //     cout << "The original tree and mirrored tree are equal." << endl;
    // } else {
    //     cout << "The original tree and mirrored tree are not equal." << endl;
    // }

    cout << "Height of tree: " << height(root) << endl;

    return 0;
}
