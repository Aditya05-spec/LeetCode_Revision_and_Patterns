#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class Node{

public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildBinaryTree(Node* &root) {

    int data;
    cout << "Enter the data : " << endl;
    cin >> data;

    //Base case
    if(data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the left child of : " << data << endl;
    root->left = buildBinaryTree(root->left);

    cout << "Enter the right child of : " << data << endl;
    root->right = buildBinaryTree(root->right);

    return root;
}

void buildBinaryTreeFromTraversal(Node* &root) {

    int data;
    cin >> data;

    root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the left data to the left of " << temp->data << endl;
        cin >> leftData;

        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter the right data to the left of " << temp->data << endl;
        cin >> rightData;

        if(rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();


        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(Node* root) {
    //LNR
    //Base case
    if(root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    //NLR
    //Base case
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    //NLR
    //Base case
    if(root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    // buildBinaryTreeFromTraversal(root);
    buildBinaryTree(root);

    levelOrderTraversal(root);

    inOrderTraversal(root);
    return 0;
}
