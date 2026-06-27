#include<iostream>
using namespace std;

void bubbleSort(int arr[] , int n) {
    for(int i=0 ; i<n-1 ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            if(arr[i] > arr[j]) {
                swap(arr[i] , arr[j]);
            }
        }
    }
}

int binarySearch(int arr[] , int n , int target) {
    int start = 0;
    int end = n-1;

    int mid = start + (end-start)/2;

    while(start < end) {
        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }

}

int main() {
    int arr[5] = {4,8,2,1,5};
    
    bubbleSort(arr , 5);

    for(int i=0 ; i<5 ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << binarySearch(arr , 5 , 5);
    return 0;
}