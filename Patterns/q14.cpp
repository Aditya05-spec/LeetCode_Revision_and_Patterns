//Tries Concepts

#include <iostream>
#include<vector>
using namespace std;

class trieNode {

    public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char d) {
        this->data = d;
        for(int i=0 ; i<26 ; i++) {
            children[i] = NULL; 
        }
        this->isTerminal = false;
    }
};

void insertWord(trieNode* root , string s) {
    //Base case
    if(s.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = s[0];
    int index = ch - 'a';
    trieNode* child;

    //Present
    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        child = new trieNode(ch);
        root->children[index] = child;
    }

    insertWord(child , s.substr(1));
}

bool SearchChild(trieNode* root , string s) {
    //Base case
    if(s.length() == 0) {
        return root->isTerminal;
    }

    char ch = s[0];
    int index = ch - 'a';
    trieNode* child;

    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else {
        return false;
    }

    return SearchChild(child , s.substr(1));
}

void storeSuggestions(trieNode* curr , vector<string> &temp , string &prefix) {
    if(curr->isTerminal) {
        temp.push_back(prefix);
    }

    for(char ch='a' ; ch<='z' ; ch++) {
        int index = ch - 'a';

        trieNode* next = curr->children[index];

        if(next != NULL) {
            prefix.push_back(ch);
            storeSuggestions(next , temp , prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string> > getSuggestions(trieNode* root , string input) {
    trieNode* prev = root;
    vector<vector<string> > output;
    string prefix = "";

    for(int i=0 ; i<input.length() ; i++) {
        char ch = input[i];
        int index = ch - 'a';

        trieNode* curr = prev->children[index];

        if(curr == NULL) {
            break;
        }
        else {
            vector<string> temp;
            prefix.push_back(ch);
            storeSuggestions(curr , temp , prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}

int main() {
    // trieNode* root = new trieNode('-');

    // insertWord(root , "LeetCode");
    // insertWord(root , "coder");
    // insertWord(root , "coding");
    // insertWord(root , "microsoft");
    // insertWord(root , "amazon");

    // if(SearchChild(root , "babu")) {
    //     cout << "It is present" << endl;
    // }
    // else {
    //     cout << "It is not present" << endl;
    // }

    vector<string> v;
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lord");
    v.push_back("lane");

    string input = "lovi";

    trieNode* root = new trieNode('-');
    for(int i=0 ; i<v.size() ; i++) {
        insertWord(root , v[i]);
    }

    vector<vector<string> > ans = getSuggestions(root , input);

    for(int i=0 ; i<ans.size() ; i++) {
        for(int j=0 ; j<ans[i].size() ; j++) {
            cout << ans[i][j] << " ,";
        }
        cout << endl;
    }

    return 0;
}