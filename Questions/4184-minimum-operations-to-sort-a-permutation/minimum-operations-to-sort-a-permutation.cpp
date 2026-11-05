class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        bool asc = true;
        bool desc = true;

        for(int i=1 ; i<n ; i++) {
            if(nums[i] != (nums[i-1] + 1) % n) asc = false;
            if(nums[i] != (nums[i-1] - 1 + n) % n) desc = false;
        }

        if(!asc && !desc) return -1;

        if(asc && nums[0] == 0) return 0;

        return min(n-nums[0] , nums[0]+2);
    }
};