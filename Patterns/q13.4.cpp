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

pair<bool , int> solve(Node* root) {
    //Base case
    if(root == NULL) {
        pair<bool , int> p = make_pair(true , INT_MIN);
        return p;
    }

    if(root->left == NULL && root->right == NULL) {
        pair<bool , int> p = make_pair(true , root->data);
        return p;
    }

    pair<bool , int> leftSubtree = solve(root->left);
    pair<bool , int> rightSubtree = solve(root->right);

    if(root->data > leftSubtree.second && root->data > rightSubtree.second && leftSubtree.first == true && rightSubtree.first == true) {
        pair<bool , int> p = make_pair(true , root->data);
        return p;
    }
    else {
        pair<bool , int> p = make_pair(false , -1);
        return p;
    }  
}

bool MaxHeapOrNot(Node* root) {
    return solve(root).first;
}

int main() {
    Node* root = NULL;
    buildBinaryTreeFromTraversal(root);
    levelOrderTraversal(root);

    if(MaxHeapOrNot(root)) {
        cout << "It is a Max heap" << endl;
    }
    else {
        cout << "It is not a max heap" << endl;
    }
    return 0;
}