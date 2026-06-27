#include <iostream>
using namespace std;

class Heap {
    public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity + 1]; 
        arr[0] = -1; 
    }

    void insert(int val) {

        if (size >= capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        //Step 1 ---> first insert the val
        size = size + 1;
        int index = size;
        arr[index] = val;

        // Step 2 ---> then place that val to the right position(sahi jagah pe lagana us value ko)
        while(index > 1) {
            int parentIndex = index/2;

            if(arr[index] > arr[parentIndex]) {
                swap(arr[index] , arr[parentIndex]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }

    int deleteNode() {
        int ans = arr[1];

        arr[1] = arr[size];
        size--;

        int index = 1;
        while(index < size) {

            int left = 2*index;
            int right = 2*index+1;

            int largest = index;
            if(left < size && arr[largest] < arr[left]) {
                largest = left;
            }

            if(right < size && arr[largest] < arr[right]) {
                largest = right;
            }

            if(largest == index) {
                break;
            }
            else {
                swap(arr[largest] , arr[index]);
                index = largest;
            }
        }

        return ans;
    }

};

void heapify(int arr[] , int n , int i) {
    int index = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;

    int largest = index;

    if(leftIndex <= n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }

    if(rightIndex <= n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }

    if(largest != index) {
        swap(arr[largest] , arr[index]);
        index = largest;
        heapify(arr , n , index);
    }
}

void buildHeap(int arr[] , int n) {
    for(int i = n/2 ; i>0 ; i--) {
        heapify(arr , n , i);
    }
}

void heapSort(int arr[] , int n) {
    int index = n;

    while(n != 1) {
        swap(arr[1] , arr[index--]);
        n--;

        //heapify
        heapify(arr , n , 1);
    }
}

int main() {
    // Heap h(10);
    //taking input in the heap
    // for(int i=0 ; i<=h.size ; i++) {
    //     cin >> h.arr[i];
    // }
    // h.insert(50);
    // h.insert(30);
    // h.insert(70);
    // h.insert(40);
    // h.insert(80);
    // h.insert(100);

    // cout << "Printing the heap : " << endl;
    // for(int i=0 ; i<=h.size ; i++) {
    //     cout << h.arr[i] << " ";
    // }cout << endl;

    // h.insert(110);

    // for(int i=0 ; i<=h.size ; i++) {
    //     cout << h.arr[i] << " ";
    // }

    int arr[] = {-1,12,56,43,6,78,87,5,44,3,23,32};
    int n = 11;

    buildHeap(arr , n);

    cout << "Printing the Heap : " << endl;

    for(int i=0 ; i<=n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr,n);

    for(int i=0 ; i<=n ; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}