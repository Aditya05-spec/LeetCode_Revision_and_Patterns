class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long allXor = 0;
        for(int i=0 ; i<nums.size() ; i++) {
            allXor = allXor ^ nums[i];
        }

        // int rightmost = (allXor & allXor-1) & allXor;
        int rightmost = allXor & (-allXor);

        int b1 = 0;
        int b2 = 0;
        for(int i=0 ; i<nums.size() ; i++) {
            if(rightmost & nums[i]) {
                b1 = b1 ^ nums[i];
            }
            else {
                b2 = b2 ^ nums[i];
            }
        }

        return {b1 , b2};
    }
};