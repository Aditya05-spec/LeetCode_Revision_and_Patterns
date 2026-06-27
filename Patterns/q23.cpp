// Count inversion problem 
#include <iostream>
#include<vector>
using namespace std;
int merge(vector<int> &arr , int s , int e , int mid) {
    vector<int> temp;

    int left = s;
    int right = mid+1;
    int count=0;

    while(left <= mid && right <= e) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            count += (mid-left+1);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= e) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=s ; i<=e ; i++) {
        arr[i] = temp[i-s];
    }

    return count;
}

int mergeSort(vector<int> &arr , int s , int e) {
    int realCount = 0;
    //Base case
    if(s>=e) {
        return realCount;
    }

    int mid = (s+e)/2;
    realCount += mergeSort(arr , s , mid);
    realCount += mergeSort(arr , mid+1 , e);

    realCount += merge(arr , s , e , mid);
    return realCount;
}

int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    // v.push_back(5);
    // v.push_back(3);
    // v.push_back(9);

    int ans = mergeSort(v , 0 , v.size());

    for(int i=0 ; i<v.size() ; i++) {
        cout << v[i] << endl;
    }
    cout << ans << endl;
    return 0;
}