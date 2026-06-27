// #include<iostream>
// #include<vector>
// #include<queue>
// #include<climits>

// using namespace std;
// class Node {

//     public: 
//     int data;
//     Node* left;
//     Node* right;

//     Node(int d) {
//         this->data = d;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };


// void buildBinaryTreeFromLevelOrderTraversal(Node* &root) {
//     int data;
//     cin >> data;

//     root = new Node(data);

//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()) {
//         Node* temp = q.front();
//         q.pop();

//         int leftData;
//         cout << "Enter the data to the left of root : " << temp->data << endl;
//         cin >> leftData;
//         if(leftData != -1) {
//             temp->left = new Node(leftData);
//             q.push(temp->left);
//         }

//         int rightData;
//         cout << "Enter the data to the right of root : " << temp->data << endl;
//         cin >> rightData;
//         if(rightData != -1) {
//             temp->right = new Node(rightData);
//             q.push(temp->right);
//         }
//     }

// }

// void levelOrderTraversal(Node* root) {
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()) {
//         Node* temp = q.front();
//         q.pop();

//         if(temp == NULL) {
//             cout << endl;
//             if(!q.empty()) {
//                 q.push(NULL);
//             }
//         }
//         else {
//             cout << temp->data << " ";
//             if(temp->left) {
//                 q.push(temp->left);
//             }
//             if(temp->right) {
//                 q.push(temp->right);
//             }
//         }
//     }
// }

// int main() {
//     Node* root = NULL;

//     buildBinaryTreeFromLevelOrderTraversal(root);
//     levelOrderTraversal(root);
// }






#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert in Binary Tree (simple left-first strategy)
Node* insertBT(Node* root, int data) {
    if (root == nullptr) return new Node(data);

    if (root->left == nullptr)
        root->left = insertBT(root->left, data);
    else if (root->right == nullptr)
        root->right = insertBT(root->right, data);
    else
        root->left = insertBT(root->left, data); // Keep filling left subtree

    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Main function with menu
int main() {
    Node* root = nullptr;
    int choice, value;
    int values[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int n = sizeof(values) / sizeof(values[0]);

    do {
        cout << "\n--- Binary Tree Operations (C++) ---\n";
        cout << "1. Create Binary Tree\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Insert a New Node\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = nullptr;
                for (int i = 0; i < n; i++)
                    root = insertBT(root, values[i]);
                cout << "Binary Tree created with predefined values.\n";
                break;

            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertBT(root, value);
                cout << "Value inserted.\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}