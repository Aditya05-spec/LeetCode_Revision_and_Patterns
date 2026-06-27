#include<iostream>
#include<vector>

using namespace std;
    
// bool subsetOrNot(vector<int>& arr, int sum , int index) { // only Recursion
//     //Base case
//     if(index == 0) {
//         return arr[0] == sum;
//     }

//     if(sum == 0) {
//         return true;
//     }

//     if(sum < 0) {
//         return false;
//     }

//     bool include = false;
//     if(arr[index] <= sum) {
//         include = subsetOrNot(arr , sum-arr[index] , index-1);
//     }
//      bool exclude = subsetOrNot(arr , sum , index-1);
    
//      bool ans = include || exclude;
//      return ans;
// }



// bool subsetOrNot(vector<int>& arr, int sum , int index , vector<vector<int> > &dp) { //Memoization and recursion
//     //Base case
//     if(index == 0) {
//         if(sum == 0) {
//             return true;
//         }
//         return arr[0] == sum;
//     }

//     if(sum < 0) {
//         return false;
//     }


//     if(dp[index][sum] != -1) {
//         return dp[index][sum];
//     }

//     bool include = false;
//     if(arr[index] <= sum) {
//         include = subsetOrNot(arr , sum-arr[index] , index-1 , dp);
//     }

//     bool exclude = subsetOrNot(arr , sum , index-1 , dp);
    
//     bool ans = include || exclude;
//     dp[index][sum] = ans;
//     return dp[index][sum];
// }

// bool subsetOrNot(vector<int>& arr, int sum , int n) { // BottomUp approach or tabulation method 2D dp
//     vector<vector<bool> > dp(n , vector<bool>(sum+1 , false));

//     dp[0][0] = true;
//     if(arr[0] <= sum) {
//         dp[0][arr[0]] = true;
//     }

//     for(int index = 1 ; index<n ; index++) {
//         for(int val = 0 ; val<=sum ; val++) {
//             bool include = false;
//             if(arr[index] <= val) {
//                 include = dp[index-1][val-arr[index]];
//             }
//             bool exclude = dp[index-1][val];
        
//             dp[index][val] = include || exclude;
//         }
//     }

//     return dp[n-1][sum];

// }

bool subsetOrNot(vector<int>& arr, int sum , int n) { // Spcae optimization using 1d dp
vector<bool> dp(sum+1 , false);

dp[0] = true;

for(auto num : arr) {
    for(int val = sum ; val>=0 ; val--) {
        bool include = false;
        if(num <= val) {
            include = dp[val-num];
        }
        bool exclude = dp[val];
        
        dp[val] = include || exclude;
    }
}

return dp[sum];

}

bool isSubsetSum(vector<int>& arr, int sum) {
    int index = arr.size();
    // return subsetOrNot(arr , sum , index-1);
    
    // vector<vector<int> > dp(index , vector<int>(sum+1 , -1));
    // return subsetOrNot(arr , sum , index-1 , dp);
    
    return subsetOrNot(arr , sum , index);
        
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(34);
    v.push_back(4);
    v.push_back(12);
    v.push_back(5);
    v.push_back(2);

    int sum = 9;

    bool ans = isSubsetSum(v , sum);
    if(ans) {
        cout << "Subset is avalaible" << endl;
    }
    else {
        cout << "Subset is not available" << endl;
    }
}

