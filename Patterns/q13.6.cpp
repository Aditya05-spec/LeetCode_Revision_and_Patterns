#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class info{
    public:
    int data;
    int row;
    int col;

    info(int val , int r , int c) {
        this->data = val;
        this->row = r;
        this->col = c;
    }
};

class compare {
    public:
    bool operator()(info* a , info* b) {
        return a->data > b->data;
    }

};

vector<int> mergeKSortedArrays(int arr[][4] , int k , int n) {
    priority_queue<info* , vector<info*> , compare> minHeap;

    //har array ka first element insert kro
    for(int i = 0 ; i<k ; i++) {
        info* temp = new info(arr[i][0] , i , 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    while(!minHeap.empty()) {
        //minHeap me top element insert kro
        info* temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();

        ans.push_back(topElement);

        //Ab check kro ki jis array ka element mene minHeap me insert kiya h uss array ke baad koi element exist krta h ya nhi agar krta h toh agle element ko minHeap me daal do bhaiya
        if(topCol+1 < n) {
            info* newInfo = new info(arr[topRow][topCol+1] , topRow , topCol+1);
            minHeap.push(newInfo);
        }
    }

    return ans;

}

int main() {
    int arr[][4] = {{2,4,6,8} , {1,3,5,7} , {0,9,10,11}};
    int k = 3;
    int n = 4;

    vector<int> ans = mergeKSortedArrays(arr , k , n);
    for(auto i : ans) {
        cout << i << " ";
    }

    return 0;
}

