#include <iostream>
using namespace std;

void merge(int *arr , int s , int e) {
    
    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = s;
    for(int i=0 ; i<len1 ; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int i = 0; i <len2 ; i++) {
        right[i] = arr[k];
        k++;
    }

    //merge logic
    int leftArrayIndex = 0;
    int rightArrayIndex = 0;
    int mainArrayIndex = s;

    while(leftArrayIndex < len1 && rightArrayIndex < len2) {
        if(left[leftArrayIndex] < right[rightArrayIndex]) {
            arr[mainArrayIndex++] = left[leftArrayIndex++];
        }
        else {
            arr[mainArrayIndex++] = right[rightArrayIndex++];
        }
    }

    //Jab ek array khatam  ho jaye aur dusra bacha ho
    while(leftArrayIndex < len1) {
        arr[mainArrayIndex++] = left[leftArrayIndex++];
    }

    while(rightArrayIndex < len2) {
        arr[mainArrayIndex++] = right[rightArrayIndex++];
    }
}

void mergeSort(int *arr , int s , int e){
    //Base case
    if(s>=e) {
        return;
    }

    int mid = (s+e)/2;

    //Left part sort krdo recursion bhaiya
    mergeSort(arr , s , mid);

    //Right part sort krdo recursion bhaiya
    mergeSort(arr , mid+1 , e);

    // Merge two sorted arrays
    merge(arr , s , e);
}

int main() {
    int arr[] = {4,5,13,2,12};
    int n=5;

    int s = 0;
    int e = n-1;
    mergeSort(arr , s , e);

    for(int i=0 ; i<n ; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}