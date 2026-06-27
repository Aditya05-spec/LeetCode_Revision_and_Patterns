#include <iostream>
#include<queue>

using namespace std;

int getKthGreaterElement(int arr[] , int n , int k) {
    //Create Min heap
    priority_queue<int , vector<int> , greater<int> > pq;

    //insert first k elements
    for(int i=0 ; i<k ; i++) {
        pq.push(arr[i]); 
    }

    //for the remaning elements push only if they greater than top
    for(int i=k ; i<n ; i++) {
        int element = arr[i];
        if(element > pq.top()) {
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;

}

int getKthSmallerElement(int arr[] , int n , int k) {
    //Create Max heap
    priority_queue<int> pq;

    //insert first k elements
    for(int i=0 ; i<k ; i++) {
        pq.push(arr[i]); 
    }

    //for the remaning elements push only if they less than top
    for(int i=k ; i<n ; i++) {
        int element = arr[i];
        if(element < pq.top()) {
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;

}

int main() {
    int arr[] = {10,5,20,4,15};
    int n=5;
    int k=2;
    // int ans = getKthSmallerElement(arr , n , k);

    int ans = getKthGreaterElement(arr , n , k);


    cout << "Kth Greatest element in the heap is : " << ans << endl;
    return 0;
}