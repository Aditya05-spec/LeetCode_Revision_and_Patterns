class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int maxi = -1e9;
        for(int i=0 ; i<nums.size() ; i++) {
            maxi = max(maxi , nums[i]);
        }

        for(auto i : nums) {
            ans += (maxi-i);
        }
        return ans;
    }
};