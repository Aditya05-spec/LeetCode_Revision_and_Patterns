#include <iostream>
#include<queue>
#include<climits>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBst(Node* root , int data) {
    //when no root present
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    // Not first Node
    if(root->data > data) {
        root->left = insertIntoBst(root->left , data);
    }
    else {
        root->right = insertIntoBst(root->right , data);
    }

    return root;

}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBst(root , data);
        cin >> data;
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

void solve(Node* root , vector<int> &inorder) {
    //Base case
    if(root == NULL) {
        return;
    }

    solve(root->left , inorder);
    inorder.push_back(root->data);
    solve(root->right , inorder);
}

void BuildMaxHeap(vector<int> &inorder , Node* root , int &index) {
    //Base case
    if(root == NULL) {
        return;
    }

    BuildMaxHeap(inorder , root->left , index);
    BuildMaxHeap(inorder , root->right , index);

    root->data = inorder[index++];
}

Node* ConvertBSTIntoMaxHeap(Node* root) {
    vector<int> inorder;
    solve(root , inorder);
    int index = 0;
    BuildMaxHeap(inorder , root , index);

    return root;
}

int main() {
    Node* root = NULL;
    takeInput(root);
    levelOrderTraversal(root);

    ConvertBSTIntoMaxHeap(root);
    levelOrderTraversal(root);
    return 0;
}