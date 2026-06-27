#include <iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class node{
    public:
    char data;
    int count;

    node(char d , int c) {
        this->data = d;
        this->count = c;
    }

};

class compare{
    public:
    bool operator()(node a , node b) {
        return a.data < b.data;
    }
};


string longestDiverseString(int a , int b , int c) {

    priority_queue<node , vector<node> , compare> maxHeap;

    if(a > 0) {
        node temp('a' , a);
        maxHeap.push(temp);
    }

    if(b > 0) {
        node temp('b' , b);
        maxHeap.push(temp);
    }

    if(c > 0) {
        node temp('c' , c);
        maxHeap.push(temp);
    }
    
    string ans = "";
    while(maxHeap.size() > 1) {
        node firstTop = maxHeap.top();
        maxHeap.pop();
        node secondTop = maxHeap.top();
        maxHeap.pop();

        if(firstTop.count >= 2) {
            ans += firstTop.data;
            ans += firstTop.data;
            firstTop.count-=2;
        }
        else {
            ans += firstTop.data;
            firstTop.count--;
        }

        if(secondTop.count >= 2) {
            ans += secondTop.data;
            ans += secondTop.data;
            secondTop.count-=2;
        }
        else {
            ans += secondTop.data;
            secondTop.count--;
        }

        if(firstTop.count != 0) {
            maxHeap.push(firstTop);
        }

        if(secondTop.count != 0) {
            maxHeap.push(secondTop);
        }
    }

    if(maxHeap.size() == 1) {
        node temp = maxHeap.top();
        maxHeap.pop();

        if(temp.count == 1){
            ans += temp.data;
        }
        else {
            return "";
        }
    }

    return ans;
    
} 

int main() {
    int a = 1;
    int b = 1;
    int c = 7;

    string s = longestDiverseString(a , b , c);

    for(auto i : s) {
        cout << i;
    }
    return 0;
}