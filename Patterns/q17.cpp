// Knapsach problem DP

#include <iostream>
#include<vector>
using namespace std;

// n = Index of last element
int solveUsingRecursion(int capacity, vector<int> &val, vector<int> &weight , int index) {
    //Base case
    if(index == 0) {
        if(weight[index] <= capacity) {
            return val[0];
        }
        else {
            return 0;
        }
    }

    // Include
    int include = 0;
    if(weight[index] <= capacity) {
        // Yaha me galti krunga value add krna bhul jayunga seedha recursive call kr dunga bina add kre ye meri galti h 
        include = val[index] + solveUsingRecursion(capacity-weight[index] , val , weight , index-1);
    }

    // Exclude
    int exclude = 0 + solveUsingRecursion(capacity , val , weight , index-1);

    int ans = max(include , exclude);
    return ans;
}

int solveUsingMemo(int capacity, vector<int> &val, vector<int> &weight , int index , vector<vector<int> > &dp) {
    //Base case
    if(index == 0) {
        if(weight[index] <= capacity) {
            return val[0];
        }
        else {
            return 0;
        }
    }

    if(dp[index][capacity] != -1) {
        return dp[index][capacity];
    }

    // Include
    int include = 0;
    if(weight[index] <= capacity) {
    include = val[index] + solveUsingMemo(capacity-weight[index] , val , weight , index-1 , dp);
    }

    // Exclude
    int exclude = 0 + solveUsingMemo(capacity , val , weight , index-1 , dp);

    int ans = max(include , exclude);
    dp[index][capacity] = ans;
    return dp[index][capacity];
}

int solveUsingTabulation(int capacity, vector<int> &val, vector<int> &weight , int n) {
    // Size kya create krna h dp ka usme fas sakta hu aur kis chezz se initilize krna h usme bhi
    vector<vector<int> > dp(n , vector<int>(capacity+1 , 0));
    
    for(int w=weight[0] ; w<=capacity ; w++) {
        
        if(weight[0] <= capacity) {
            dp[0][w] = val[0];
        }
        else {
            dp[0][w] = 0;
        }
    }

    for(int index = 1 ; index<n ; index++) {
        for(int cap = 0 ; cap<=capacity ; cap++) {
            int include = 0;
            if(weight[index] <= cap) {
                include = val[index] + dp[index-1][cap-weight[index]];
            }

            // Exclude
            int exclude = 0 + dp[index-1][cap];

            dp[index][cap] = max(include , exclude);
        }
    }
    // n-1 kyu liya h kukii humne value jo pass ki h uspe depend krta h n=3 pass kiya h toh last row to 2 h isliye n-1 kiya h yaha bhi galti kr sakta hu 
    return dp[n-1][capacity];
}

int solveUsingSpaceOptimization(int capacity, vector<int> &val, vector<int> &weight , int n) {
    vector<int> prev(capacity+1 , 0);
    vector<int> curr(capacity+1 , 0);
    
    for(int w=weight[0] ; w<=capacity ; w++) {
        
        if(weight[0] <= capacity) {
            prev[w] = val[0];
        }
        else {
            prev[w] = 0;
        }
    }

    for(int index = 1 ; index<n ; index++) {
        for(int cap = 0 ; cap<=capacity ; cap++) {
            int include = 0;
            if(weight[index] <= cap) {
                include = val[index] + prev[cap-weight[index]];
            }

            int exclude = 0 + prev[cap];

            curr[cap] = max(include , exclude);
        }
        // Shift Yaha pe Me galti krunga acche se yaad rakhna h mughe ise ki yahaa aisa kyu kiya h mene 
        prev = curr;
    }
    return prev[capacity];
}

int solveUsingSpaceOptimization2(int capacity, vector<int> &val, vector<int> &weight , int n) {
    vector<int> curr(capacity+1 , 0);
    
    for(int w=weight[0] ; w<=capacity ; w++) {
        
        if(weight[0] <= capacity) {
            curr[w] = val[0];
        }
        else {
            curr[w] = 0;
        }
    }

    for(int index = 1 ; index<n ; index++) {
        for(int cap = capacity ; cap>=0 ; cap--) {
            int include = 0;
            if(weight[index] <= cap) {
                include = val[index] + curr[cap-weight[index]];
            }

            int exclude = 0 + curr[cap];

            curr[cap] = max(include , exclude);
        }
    }
    return curr[capacity];
}

int main() {
    
    vector<int> weight;
    weight.push_back(4);
    weight.push_back(5);
    weight.push_back(1);
    
    vector<int> value;
    value.push_back(1);
    value.push_back(2);
    value.push_back(3);

    int n = 3;
    int capacity = 4;

    // ---------->Using recursion <----------- 
    // int ans = solveUsingRecursion(capacity , value , weight , n-1);

    // --------> Using memoization <---------------
    // Yaha pe size of dp kya lena h waha galti kr skata hu me
    // vector<vector<int> > dp(n , vector<int>(capacity+1 , -1));
    // int ans = solveUsingMemo(capacity , value , weight , n-1 , dp);

    // int ans = solveUsingTabulation(capacity , value , weight , n);

    // int ans = solveUsingSpaceOptimization(capacity , value , weight , n);

    int ans = solveUsingSpaceOptimization2(capacity , value , weight , n);

    cout << "Ans is : " << ans << endl;
    return 0;
}