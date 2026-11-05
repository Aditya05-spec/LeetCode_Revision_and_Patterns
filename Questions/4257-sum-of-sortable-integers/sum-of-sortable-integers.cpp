class Solution {
private:
    bool check(vector<int> &nums , int len) {
        int n = nums.size();
        int prevMax = -1;
        for(int i=0 ; i<n ; i+=len) {
            int descent = 0;
            int blockMin = nums[i];
            int blockMax = nums[i];
            for(int j=i ; j<i+len-1 ; j++) {
                if(nums[j] > nums[j+1]) descent++;
                blockMin = min(blockMin , nums[j]);
                blockMax = max(blockMax , nums[j]);
            }
            blockMin = min(blockMin , nums[i+len-1]);
            blockMax = max(blockMax , nums[i+len-1]);

            if(descent == 0) {
                
            }
            else if(descent == 1) {
                if(nums[i] < nums[i+len-1]) return false;
            }
            else {
                return false;
            }

            if(prevMax > blockMin) return false;
            prevMax = blockMax;
        }
        return true;
    }
    
public:
    int sortableIntegers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=1 ; i<=n ; i++) {
            if(n%i != 0) continue;
            if(check(nums , i)) {
                ans += i;
            }
        }
        return ans;
    }
};