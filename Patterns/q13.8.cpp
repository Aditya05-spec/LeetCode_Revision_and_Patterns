// Median of a stream

#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int signum(int a , int b) {
    if(a == b) {
        return 0;
    }
    if(a > b) {
        return 1;
    }
    if(a < b) {
        return 2;
    }
}

void callMedian(int &median , priority_queue<int> &maxHeap , priority_queue<int , vector<int> , greater<int> > &minHeap , int element) {

    switch (signum(minHeap.size() , maxHeap.size())) {
        
        case 0 : if(element > median) {
            minHeap.push(element);
            median = minHeap.top();
        }
        else {
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;

        case 1 : if(element > median) {
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top())/2;
        }
        else {
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top())/2;
        }
        break;

        case 2 : if(element > median) {
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top())/2;
        }
        else {
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top())/2;
        }

    }
}

int main() {
    priority_queue<int> maxHeap;
    priority_queue<int , vector<int> , greater<int> > minHeap;

    int arr[] = {5,7,2,9,3,8};
    int n = 6;

    int median = 0;
    for(int i=0 ; i<n ; i++) {
        int element = arr[i];
        callMedian(median , maxHeap , minHeap , element);
        cout << "Median of the current array is : " << median << endl;
    }
    return 0;
}