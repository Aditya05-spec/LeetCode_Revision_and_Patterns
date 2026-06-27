#include <iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> &arr , int &n , int i) {
    //Base case
    if(i>=n) {
        return true;
    }

    if(arr[i] >= arr[i-1]) {
        isSorted(arr , n , i+1);
    }
    else {
        return false;
    }
}

int binarySearch(vector<int> arr , int s , int e , int target) {
    //Base case
    if(s > e) {
        return -1;
    }
    int mid = s + (e-s)/2;

    //Base case
    if(arr[mid] == target) {
        return mid;
    }

    if(arr[mid] > target) {
        int leftAns = binarySearch(arr , s , mid-1 , target);
        return leftAns;
    }
    else {
        int rightAns = binarySearch(arr , mid+1 , e , target);
        return rightAns;
    }
}

int main() {
    
}