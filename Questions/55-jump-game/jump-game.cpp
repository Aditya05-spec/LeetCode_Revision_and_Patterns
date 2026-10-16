class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;

        // int currEnd = 0;
        int farthest = 0;
        for(int i=0 ; i<nums.size()-1 ; i++) {
            farthest = max(farthest , i+nums[i]);

            if(nums[i] == 0) {
                if(farthest == i) {
                    return false;
                }
            }
        }
        return true;
    }
};