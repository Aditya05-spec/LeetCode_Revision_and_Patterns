#include <iostream>
#include<queue>
#include<map>
#include<climits>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }


};

Node* buildBinaryTree(Node* &root) {
    //Base case

    int data;
    cin >> data;

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

int convertSumTree(Node* root) {
    //Base case
    if(root == NULL) {
        return 0;
    }

    int leftAns = convertSumTree(root->left);
    int rightAns = convertSumTree(root->right);

    root->data = root->data + leftAns + rightAns;

    return root->data;
}

bool kthAncestor(Node* root , int &k , int p) {

    // Base case
    if(root == NULL) {
        return false;
    }

    if(root->data == p) {
        return true;
    }

    bool leftAns = kthAncestor(root->left , k , p);
    bool rightAns = kthAncestor(root->right , k , p);

    if(leftAns == true || rightAns == true) {
        k--;
    }

    if(k == 0) {
        cout << root->data << endl;
        k=-1;
    }

    return leftAns || rightAns;


}

Node* lca(Node* root , int p , int q) {
    //Base case
    if(root == NULL) {
        return NULL;
    }

    if(root->data == p) {
        return root;
    }

    if(root->data == q) {
        return root;
    }

    Node* leftAns = lca(root->left , p , q);
    Node* rightAns = lca(root->right , p , q);

    if(leftAns == NULL && rightAns == NULL) {
        return NULL;
    }

    else if(leftAns != NULL && rightAns == NULL) {
        return leftAns;
    }

    else if(leftAns == NULL && rightAns != NULL) {
        return rightAns;
    }
    
    else {
        return root;
    }
}

void solve(Node* root , int targetSum , int &sum , vector<vector<int> > &ans , vector<int> current) {
    //Base case
    if(root == NULL) {
        return;
    }

    if(root->left == NULL && root->right == NULL) {
        current.push_back(root->data);
        sum += root->data;
        if(sum == targetSum) {
            ans.push_back(current);
        } 
        //Backtracking
        current.pop_back();
        sum -= root->data;
    }

    current.push_back(root->data);
    sum += root->data;

    solve(root->left , targetSum , sum , ans , current);
    solve(root->right , targetSum , sum , ans , current);
    
    //Backtracking
    current.pop_back();
    sum -= root->data;


}

vector<vector<int> > pathSum(Node* root , int targetSum) {

    vector<vector<int> > ans;
    vector<int> current;

    int sum = 0;
    solve(root , targetSum , sum , ans , current);

    return ans;
}

vector<vector<int> > zigzagTraversal(Node* root) {
    vector<vector<int> > result;

    if(root == NULL) {
        return result;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> ans(size);

        for(int i=0 ; i<size ; i++) {
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size-i-1;
            ans[index] = frontNode->data;

            if(frontNode->left) {
                q.push(frontNode->left);
            }
            if(frontNode->right) {
                q.push(frontNode->right);
            }
        }
        leftToRight = !leftToRight;

        result.push_back(ans);
    }
    return result;
}

void traverseLeft(Node* root , vector<int> &ans) {
    //Base case
    if((root == NULL) || (root->left == NULL && root->right == NULL)) {
        return;
    }

    ans.push_back(root->data);

    if(root->left) {
        traverseLeft(root->left , ans);
    }
    else {
        traverseLeft(root->right , ans);
    }

}

void traverseLeaf(Node* root , vector<int> &ans) {
    //Base case
    if(root == NULL) {
        return;
    }

    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->data); 
        return;
    }

    traverseLeaf(root->left , ans);
    traverseLeaf(root->right , ans);

}

void traverseRight(Node* root , vector<int> &ans) {
    //Base case
    if((root == NULL) || (root->left == NULL && root->right == NULL)) {
        return;
    }
    if(root->right) {
        traverseRight(root->right , ans);
    }
    else {
        traverseLeft(root->left , ans); 
    }

    ans.push_back(root->data);

}

vector<int> boundaryTraversal(Node *root) {
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }

    ans.push_back(root->data);

    //root ka left print/store except leaf node
    traverseLeft(root->left , ans);

    //left subtree leaf node
    traverseLeaf(root->left , ans);

    //right subtree leaf node
    traverseLeaf(root->right , ans);

    //root ka right part print/store except leaf node
    traverseRight(root->right , ans);

    return ans;

}

vector<int> verticalOrderTraversal(Node* root) {
    map<int , map<int , vector<int> > > nodes;
    queue<pair<Node* , pair<int, int> > > q;
    vector<int> result;

    if(root == NULL) {
        return result;
    }

    q.push(make_pair(root , make_pair(0,0)));

    while(!q.empty()) {
        pair<Node* , pair<int , int> > temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left) {
            q.push(make_pair(frontNode->left , make_pair(hd-1 , lvl+1)));
        }

        if(frontNode->right) {
            q.push(make_pair(frontNode->right , make_pair(hd+1 , lvl+1)));
        }
    }

    for(auto i : nodes) {
        
        for(auto j : i.second) {

            for(auto k : j.second) {
                result.push_back(k);
            }
        }
    }
    return result;
}

vector<int> topView(Node *root) {

    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    map<int , int> topNode;
    queue<pair<Node* , int> > q;

    q.push(make_pair(root,0));

    while(!q.empty()) {
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left) {
            q.push(make_pair(frontNode->left , hd-1));
        }

        if(frontNode->right) {
            q.push(make_pair(frontNode->right , hd+1));
        }
    }

    for(auto i : topNode) {
        ans.push_back(i.second);
    }

    return ans; 
}

vector<int> bottomView(Node* root) {
    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<Node* , int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node* , int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if(frontNode->left) {
            q.push(make_pair(frontNode->left , hd-1));
        }

        if(frontNode->right) {
            q.push(make_pair(frontNode->right , hd+1));
        }
    }

    for(auto i : topNode) {
        ans.push_back(i.second);
    }
}

void solve(Node* root , vector<int> &ans , int lvl) {
    //base case
    if(root == NULL) {
        return;
    }

    if(lvl == ans.size()) {
        ans.push_back(root->data);
    }

    solve(root->right , ans , lvl+1);
    solve(root->left , ans , lvl+1);
}

vector<int> rightView(Node* root) {
    vector<int> ans;
    solve(root , ans , 0);
    return ans;
    
}

Node* createMapping(Node* root , map<Node* , Node*> &nodeToParent , int target) {
    Node* res = NULL;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* frontNode = q.front();
        q.pop();

        if(frontNode->data == target) {
            res = frontNode;
        }

        if(frontNode->left) {
            nodeToParent[frontNode->left] = frontNode;
            q.push(frontNode->left);
        }

        if(frontNode->right) {
            nodeToParent[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
    return res;
}

int burnTree(Node* root , map<Node* , Node*> &nodeToParent) {
    map<Node* , bool> visited;
    queue<Node*> q;
    int ans = 0;

    q.push(root);
    visited[root] = true;

    while(!q.empty()) {
        int size = q.size();
        bool flag = false;

        for(int i=0 ; i<size ; i++) {
            Node* frontNode = q.front();
            q.pop();

            if(frontNode->left && !visited[frontNode->left]) {
                q.push(frontNode->left);
                visited[frontNode->left] = true;
                flag = true;
            }

            if(frontNode->right && !visited[frontNode->right]) {
                q.push(frontNode->right);
                visited[frontNode->right] = true;
                flag = true;
            }

            if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]) {
                q.push(nodeToParent[frontNode]);
                visited[nodeToParent[frontNode]] = true;
                flag = true;
            }
        }
        
        if(flag == true) {
            ans++;
        }
    }

    return ans;
}

int amountOfTime(Node* root , int target) {
    map<Node* , Node*> NodeToParent;
    Node* targetNode = createMapping(root , NodeToParent , target);

    int ans = burnTree(targetNode , NodeToParent);

    return ans;

}

void solve(Node* root , int sum , int &maxSum , int len , int &maxLen) {
    //Base case
    if(root == NULL) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }

        if(len == maxLen) {
            maxSum = max(sum , maxSum);
        }
        return;
    }

    sum = sum + root->data;
    solve(root->left , sum , maxSum , len+1 , maxLen);
    solve(root->right , sum , maxSum , len+1 , maxLen);

}

int sumOfLongRootToLeafPath(Node* root) {
    int sum = 0;
    int maxSum = INT_MIN;

    int len = 0;
    int maxLen = 0;

    solve(root , sum , maxSum , len , maxLen);

    return maxSum;
}

pair<int , int> fastDimeter(Node* root) {

    //Base case
    if(root == NULL) {
        pair<int , int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = fastDimeter(root->left);       
    pair<int, int> right = fastDimeter(root->right);    

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int , int> ans;
    ans.first = max(op1 , max(op2 , op3));
    ans.second = max(left.second , right.second) + 1;
    
    return ans;

}

int diameter(Node* root) {
    return fastDimeter(root).first;
}


pair<int , int> solve(Node* root) {
    //Base case
    if(root == NULL) {
        pair<int , int> p = make_pair(0,0);
        return p;
    }

    pair<int ,int> left = solve(root->left);
    pair<int ,int> right = solve(root->right);

    pair<int , int> ans ;
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first , left.second) + max(right.first , right.second);

    return ans;
}

int rob(Node* root) {  
    pair<int ,int> ans = solve(root);
    return max(ans.first , ans.second);

}


void solve(Node* root , int targetSum , vector<int> &path , int &count) {
    //Base case
    if(root == NULL) {
        return;
    }

    path.push_back(root->data);

    solve(root->left , targetSum , path , count);

    solve(root->right , targetSum , path , count);

    int size = path.size();
    long long sum = 0;
    for(int i=size-1 ; i>=0 ; i--) {
        sum += path[i];
        if(sum == targetSum) {
            count++;
        }   
    }

    //Backtracking
    path.pop_back();
}

int kSumPath(Node* root , int targetSum) {
    vector<int> ans;
    int count = 0;
    solve(root , targetSum , ans , count);
    return count;
}

int main() {
    Node* root = NULL;
    buildBinaryTreeFromTraversal(root);

    levelOrderTraversal(root);

    // convertSumTree(root);

    // levelOrderTraversal(root);

    // cout << "Lowest common ancestor of the tree is : " << lca(root , 7 , 17)->data;
    
    // int k = 1;
    // bool found = kthAncestor(root , k , 11);


    // ----------->leet code question on path sum 2 (we just need to return the 3d vector of different path that add up to the targetsum)<-----------
    // vector<vector<int> > result = pathSum(root , 22);

    // for(auto i : result) {
    //     cout << "[ ";
    //     for(auto j : i) {
    //         cout << j << " ";
    //     } cout << "]";
    // }



    //          ----------------->Zig Zag traversal,--------------------
    // vector<vector<int> > zigZagView = zigzagTraversal(root);
    
    // for(auto i : zigZagView) {
    //     for(auto j : i) {
    //         cout << j << " ";
    //     }
    // }

    // -------------------------------> BOUNDARY TRAVERSAL <----------------------------------------------
    // vector<int>result = boundaryTraversal(root);
    // for(auto i : result) {
    //     cout << i << " ";
    // }


    // ------------------------> VERTICAL ORDER TRAVERSAL  <------------------------------
    // vector<int> result = verticalOrderTraversal(root);

    // for(auto i : result) {
    //     cout << i << " ";
    // }

    // ------------------------------------> Top View <---------------------------------------------
    // vector<int> result = topView(root);
    // for(auto i : result) {
    //     cout << i << " " ;
    // }

    // ------------------------------------> Bottom View <---------------------------------------------
    // vector<int> result = bottomView(root);
    // for(auto i : result) {
    //     cout << i << " " ;
    // }

    // -------------------------------> right side View <---------------------------------------------
    // vector<int> result = rightView(root);
    // for(auto i : result) {
    //     cout << i << " " ;
    // }


    // ------------------------------> Burning Tree <---------------------------------------
    // int ans = amountOfTime(root , 8);
    // cout << "Amount of time taken by tree to burn is : " << ans << endl;


    // ------------------------> Sum of longest BloodLine <--------------------------------------
    // int ans = sumOfLongRootToLeafPath(root);
    // cout << "Sum of the longest bloodline in the given tree is : " << ans << endl;

    // ----------------------------------> Diameter of a Binary Tree <--------------------------------------
    // int ans = diameter(root);
    // cout << "Diameter of the given tree is : " << ans << endl;


    // ---------------------------> House Robber 3 problem on leetcode(337) <------------------------------
    // int ans = rob(root);
    // cout << "maximum about of money the robber can get will be : " << ans << endl;

    // -------------------------------------------> kSumPath problem <-------------------------------------------
    // int ans = kSumPath(root , 8);
    // cout << "Number of path that sum up to target sum are : " << ans << endl;

    // ----------------------------------------> Convert Binary tree to Linked List <--------------------------------------------
    

    // ------------------------------------------> Morris Traversal <----------------------------------------
    



    return 0;
}