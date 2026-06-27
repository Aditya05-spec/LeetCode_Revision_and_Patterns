#include <iostream>
using namespace std;
//find missing element along with duplicate 

void findMissing(int arr[] , int n) {

    // for(int i=0 ; i<5 ; i++) {
    //     int index = abs(arr[i]);
    //     if(arr[index-1] > 0) {
    //         arr[index-1] *= -1;
    //     }
    // }

    int i=0;
    while(i<n) {
        int index = arr[i]-1;
        if(arr[i] != arr[index]) {
            swap(arr[i] , arr[index]);
        }
        else {
            i++;
        }
    }
} 

int main() {
    int arr[5] = {1,3,5,3,4};

    findMissing(arr,5);

    for(int i=0 ; i<5 ; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}