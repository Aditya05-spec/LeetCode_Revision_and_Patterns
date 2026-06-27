#include <iostream>
#include<vector>
#include<string>
using namespace std;

// bool canWeDoPartitionOrNOt(vector<int>& nums , int index , int target) { //Only Recursion
//     //Base case
//     if(index == 0) {
//         return nums[0] == target;
//     }

//     if(target == 0) {
//         return true;
//     }

//     if(target < 0) {
//         return false;
//     }

//     bool include = false;
//     if(nums[index] <= target) {
//         include = canWeDoPartitionOrNOt(nums , index-1 , target-nums[index]);
//     }

//     bool exclude = canWeDoPartitionOrNOt(nums , index-1 , target);

//     bool ans = include || exclude;

//     return ans;
// }

// bool canWeDoPartitionOrNOt(vector<int>& nums , int index , int target , vector<vector<bool> > dp) { //Recrsion with memoization
//     //Base case
//     if(index == 0) {
//         return nums[0] == target;
//     }

//     if(target == 0) {
//         return true;
//     }

//     if(target < 0) {
//         return false;
//     }

//     if(dp[index][target] != false) {
//         return dp[index][target];
//     }

//     bool include = false;
//     if(nums[index] <= target) {
//         include = canWeDoPartitionOrNOt(nums , index-1 , target-nums[index] , dp);
//     }

//     bool exclude = canWeDoPartitionOrNOt(nums , index-1 , target , dp);

//     bool ans = include || exclude;
//     dp[index][target] = ans;

//     return dp[index][target];
// }

// bool canWeDoPartitionOrNOt(vector<int>& nums , int n , int target) { //Using BottomUp approach or Tabulation method (Using 2D Dp)
//     vector<vector<bool> > dp(n , vector<bool>(target+1 , false));
//     dp[0][0] = true;
//     if(nums[0] <= target) {
//         dp[0][nums[0]] = true;
//     }

// We can also mark true the dp in the first by other way upar ek dikhaya h aur ek ye neeche dekh lo
// for(int i=0 ; i<target.size() ; i++) {
//     dp[i][0] = true;
// }

//     for(int index = 1 ; index<n ; index++) {
//         for(int val = 0 ; val<=target ; val++) {
//             bool include = false;
//             if(nums[index] <= val) {
//                 include = dp[index-1][val-nums[index]];
//             }

//             bool exclude = dp[index-1][val];

//             bool ans = include || exclude;
//             dp[index][val] = ans;
//         }
//     }
//     return dp[n-1][target];
// } 

// bool canWeDoPartitionOrNOt(vector<int>& nums , int n , int target) { //Using space optimisation method (Using 2 1D Dp)
//     vector<bool> curr(target+1 , false);
//     vector<bool> prev(target+1 , false);
//     curr[0] = true;
//     prev[0] = true;

//     for(int index = 1 ; index<n ; index++) {
//         for(int val = 0 ; val<=target ; val++) {
//             bool include = false;
//             if(nums[index] <= val) {
//                 include = prev[val-nums[index]];
//             }

//             bool exclude = prev[val];

//             bool ans = include || exclude;
//             curr[val] = ans;
//         }
//         prev = curr;
//     }
//     return prev[target];
// } 


bool canWeDoPartitionOrNOt(vector<int>& nums , int n , int target) {  //Using 1D dp most optimised solution
    vector<bool> dp(target+1 , false);

    dp[0] = true;
    for(auto num : nums) {
        for(int val=target ; val>=0 ; val--) {
            bool include = false;
            if(num <= val) {
                include = dp[val-num];
            }

            bool exclude = dp[val];

            bool ans = include || exclude;
            dp[val] = ans;
        }
    }
    return dp[target];
}

bool canPartition(vector<int>& nums) {
    int index = nums.size();
    int target = 0;
    for(auto i : nums) {
        target += i;
    }
    // bool ans = canWeDoPartitionOrNOt(nums , index-1 , target/2);


    // vector<vector<bool> > dp(index , vector<bool>(target+1 , false));
    // bool ans = canWeDoPartitionOrNOt(nums , index-1 , target/2 , dp);

    // bool ans = canWeDoPartitionOrNOt(nums , index-1 , target/2);

    bool ans = canWeDoPartitionOrNOt(nums , index-1 , target/2);

    return ans;
    
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(11);
    v.push_back(5);
    

    if(canPartition(v)) {
        cout << "We can" << endl;
    }
    else {
        cout << "We can't" << endl;
    }
    return 0;
}