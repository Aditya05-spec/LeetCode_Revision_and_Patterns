#include <iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;


// -----------------------------> Prefix sum approach <-------------------------------------
int largestSubarrayWithSumK(vector<int> &nums , int k) {

    // --------------> Better solution((for array containing posititve and zeroes and negatives) <--------------------
    // int maxLen = 0;
    // unordered_map<long long , int> preMapp;
    // long long sum = 0;

    // for(int i=0 ; i<nums.size() ; i++) {
    //     sum += nums[i];
    //     if(sum == k) {
    //         maxLen = max(maxLen , i+1);
    //     }

    //     long long rem = sum - k;
    //     if(preMapp.find(rem) != preMapp.end()) {
    //         int len = i - preMapp[rem];
    //         maxLen = max(maxLen , len);
    //     }
    //     if(preMapp.find(sum) == preMapp.end()) {
    //         preMapp[sum] = i;
    //     }
    // }

    // -------------------->Most optimal one(for array containing posititve and zeroes) <-----------------------------
    int maxLen = 0;
    int left = 0;
    int right = 0;
    long long sum = nums[right];

    while(right < nums.size()) {

        while(left < right && sum > k) {
            sum -= nums[left];
            left++;
        }


        if(sum == k) {
            maxLen = max(maxLen , right-left+1);
        }
        right++;
        if(right < nums.size()) {
            sum += nums[right];
        }
    }
    
    return maxLen;
}


// Longest subarray with atmost k distinct characters
int longestSubarray(string s , int k) {
    int left = 0;
    int right = 0;
    unordered_map<char , int> freq;
    int maxLen = 0;

    while(right < s.length()) {
        freq[s[right]]++;
        if(freq.size() > k) {
            freq[s[left]]--;
            if(freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        if(freq.size() <= k) {
            maxLen = max(maxLen , right-left+1);
        }
        right++;
    }
    return maxLen;
}

int main() {


    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(4);
    // v.push_back(2);
    // v.push_back(3);

    // int ans = largestSubarrayWithSumK(v , 3);


    string s = "aaabbccd";
    int k = 2;

    int ans = longestSubarray(s , k);
    cout << ans << endl;
    return 0;
}