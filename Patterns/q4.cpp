#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> removeElement(vector<int>& nums, int val) {
    int i=0 ;
    int j=nums.size()-1;

    while(i<j) {
        if(nums[j] == val) {
            j--;
        }
        if(nums[j] != val && nums[i] == val) {
            swap(nums[i] , nums[j]);
            i++;
        }
        if(nums[j] != val && nums[i] != val) {
            i++;
        }
    }
    return nums;
}

int main() {
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(0);
    v.push_back(4);
    v.push_back(2);

    vector<int> ans = removeElement(v , 2);

    for(auto i : ans) {
        cout << i << " ";
    }
}