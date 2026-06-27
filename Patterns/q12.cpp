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

class NodeData {
    public:
    int size;
    int maxval;
    int minval;
    bool validBST;

    NodeData() {

    }

    NodeData(int size , int max , int min , bool valid) {
        this->size = size;
        maxval = max;
        minval = min;
        validBST = valid;
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

void postOrderTraversal(Node* root) {
    //LRN
    //Base case
    if(root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

bool findNodeInBst(Node* root , int target) {
    //Base case
    if(root == NULL) {
        return false;
    }

    //if target found
    if(root->data == target) {
        return true;
    }

    bool leftAns = false;
    bool rightAns = false;
    if(root->data < target) {
        //Right subtree me search kro
        leftAns =  findNodeInBst(root->right , target);
    }
    else {
        //Left subtree me search kro
        rightAns =  findNodeInBst(root->left , target);
    }

    return leftAns || rightAns;
}

int minVal(Node* root) {
    Node* temp = root;
    if(temp == NULL) {
        return -1;
    }

    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp->data;
}

int maxVal(Node* root) {
    Node* temp = root;
    if(temp == NULL) {
        return -1;
    }

    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}

pair<Node* , Node*> inorderPredecessorSucessor(Node* root , int val) {
    Node* temp = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(temp->data != val) {
        if(temp->data > val) {
            succ = temp;
            temp = temp->left;
        }
        else {
            pred = temp;
            temp = temp->right;
        }
    }

    //Predecessor and Sucessor    
    Node* leftTree = temp->left;
    while(leftTree != NULL) {
        pred = leftTree;
        leftTree = leftTree->right;
    }

    Node* rightTree = temp->right;
    while(rightTree != NULL) {
        succ = rightTree;
        rightTree = rightTree->left;
    }

    pair<Node* , Node*> ans = make_pair(pred , succ);
    return ans;


}

Node* deleteNodeInBST(Node* root , int target) {
    //Base case
    if(root == NULL) {
        return NULL;
    }

    if(root->data == target) {
        //4 cases
        //leaf Node
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else {
            //both child
            int inorderpred = maxVal(root->left);
            root->data = inorderpred;
            root->left = deleteNodeInBST(root->left , inorderpred);
            return root;
        }
    }
    else if(root->data < target) {
        //We have to go to the right part
        root->right =  deleteNodeInBST(root->right , target);
    }
    else if(root->data > target) {
        //We have to go to the left part
        root->left =  deleteNodeInBST(root->left , target);
    }
    return root;
}

void convertBSTIntoSortedDLL(Node* root , Node* &head) {
    //Base case
    if(root == NULL) {
        return;
    }

    //right subtree into linked list
    convertBSTIntoSortedDLL(root->right , head);

    //attach root node
    root->right = head;

    //head ka prev bhi toh lagao bhai
    if(head != NULL) {
        head->left = root;
    }

    //update head
    head = root;

    //left subtree to linked list
    convertBSTIntoSortedDLL(root->left , head); 
}

Node* sortedLinkedListToBST(Node* &head , int n) {
    //Base case
    if(n <= 0 || head == NULL) {
        return NULL;
    }

    Node* leftSubtree = sortedLinkedListToBST(head , n/2);

    Node* root = head;

    root->left = leftSubtree;

    head = head->right;

    root->right = sortedLinkedListToBST(head , n-1-n/2);

    return root;
}

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

NodeData* largetBSTInBinaryTree(Node* root , int &ans) {
    //Base case
    if(root == NULL) {
        NodeData* temp = new NodeData(0 , INT_MIN , INT_MAX , true);
        return temp;
    }

    NodeData* leftKaAns = largetBSTInBinaryTree(root->left , ans);
    NodeData* rightKaAns = largetBSTInBinaryTree(root->right , ans);

    NodeData* currKaAns = new NodeData();
    currKaAns->size = leftKaAns->size + rightKaAns->size + 1;
    currKaAns->maxval = max(root->data , rightKaAns->maxval);
    currKaAns->minval = min(root->data , leftKaAns->minval);
    
    if(leftKaAns->validBST && rightKaAns->validBST &&(root->data > leftKaAns->maxval && root->data < rightKaAns->minval)) {
        currKaAns->validBST = true;
    }
    else {
        currKaAns->validBST = false;
    }

    if(currKaAns->validBST) {
        ans = max(ans , currKaAns->size);
    }

    return currKaAns;

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

int main() {
    Node* root = NULL;
    cout << "Enter the data for Node " << endl;

    // takeInput(root);
    buildBinaryTreeFromTraversal(root);
    levelOrderTraversal(root);
    
    // -------------------------> Inorder , PreOrder and PostOrder Traversal <------------------------------------
    // cout << endl;
    // cout << "Printing Inorder Traversal : " << endl;
    // inOrderTraversal(root);

    // cout << endl;
    // cout << "Printing Preorder Traversal : " << endl;
    // preOrderTraversal(root);

    // cout << endl;
    // cout << "Printing Postorder Traversal : " << endl;
    // postOrderTraversal(root);

    // ----------------------------> Search Node In A BST <----------------------------------
    // cout << endl;
    // bool ans = findNodeInBst(root , 15);
    // cout << "Present or Not : " << ans << endl << endl;

    // -------------------------------> Min value <---------------------------------
    // int ans = minVal(root);
    // cout << "Minimum value of the binary tree : " << ans << endl;

    // ----------------------------> max value <--------------------------------
    // int result = maxVal(root);
    // cout << "Minimum value of the binary tree : " << result << endl;

    // ------------------------------> Inorder predecessor and Sucessor <-----------------------------------
    // pair<Node*, Node*> ans = inorderPredecessorSucessor(root , 5);
    // cout << "Predecessor of the Tree is : " << ans.first->data << endl;
    // cout << "Sucessor of the Tree is : " << ans.second->data << endl;

    // ------------------------> Delete Node Form A BST <--------------------------------------
    // Node* ans = deleteNodeInBST(root , 100);
    // levelOrderTraversal(root);


    // -------------------------------> Convert BST to Doubly Linked List and to BST
    // Node* head = NULL;
    // convertBSTIntoSortedDLL(root , head);
    // print(head);

    // Node* root1 = NULL;

    // root1 = sortedLinkedListToBST(head , 9);
    // cout << endl;
    // levelOrderTraversal(root1);



    // -------------------------------------> largest BST in a Binary Tree <----------------------------------
    int ans = 0;
    largetBSTInBinaryTree(root , ans);
    cout << "Largest BST ka size : " << ans;

    return 0;
}