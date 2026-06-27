#include <iostream>
#include<queue>
#include<vector>
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

pair<bool , int> solveMaxHeapOrNot(Node* root) {
    //Base case
    if(root == NULL) {
        pair<bool , int> p = make_pair(true , INT_MIN);
        return p;
    }
    
    if(root->left == NULL && root->right == NULL) {
        pair<bool , int> p = make_pair(true , root->data);
        return p;
    }
    
    pair<bool , int> leftSubtree = solveMaxHeapOrNot(root->left);
    pair<bool , int> rightSubtree = solveMaxHeapOrNot(root->right);
    
    if(leftSubtree.first == true && rightSubtree.first == true && root->data > leftSubtree.second && root->data > rightSubtree.second) {
        pair<bool , int> currNode = make_pair(true , root->data);
        return currNode;
    }
    else {
        pair<bool , int> currNode = make_pair(false , root->data);
        return currNode;
    }
}
  
bool maxHeapOrNot(Node* tree) {
    return solveMaxHeapOrNot(tree).first;
}

int nodecountTree(Node* root) {
    //Base case
    if(root == NULL) {
        return 0;
    }
    
    int left = nodecountTree(root->left);
    int right = nodecountTree(root->right);
    
    int curr = 1 + left + right;
    
    return curr;
}
    
bool isCBT(Node* root , int i , int &n) {
    if(root == NULL) {
        return true;
    }
    
    if(i > n) {
        return false;
    }
    
    bool left = isCBT(root->left , 2*i , n);
    bool right = isCBT(root->right , 2*i+1 , n);
    
    return left && right;
}


bool isHeap(Node* tree) {
        
    int n = nodecountTree(tree);
    int i=1;
    return isCBT(tree , i , n) && maxHeapOrNot(tree);
}

int main() {
    Node* root = NULL;
    buildBinaryTreeFromTraversal(root);
    levelOrderTraversal(root);

    if(isHeap(root)) {
        cout << "Given Binary Tree is Max Heap" << endl;
    }
    else {
        cout << "Given Binary Tree is not a Max Heap" << endl;
    }
    return 0;
}

 