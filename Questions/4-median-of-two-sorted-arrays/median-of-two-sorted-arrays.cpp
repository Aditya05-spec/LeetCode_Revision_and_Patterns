class Solution {
private:
    vector<int> mergedArray(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int> output;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                output.push_back(nums1[i]);
                i++;
            }
            else {
                output.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()) {
            output.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()) {
            output.push_back(nums2[j]);
            j++;
        }

        return output;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> resultant = mergedArray(nums1 , nums2);
        int start = 0;
        int end = resultant.size()-1;
        if(resultant.size() % 2 == 0) {
            int first = (start+end)/2;
            int second = first+1;
            double ans = (resultant[first] + resultant[second]);
            return ans/2;
        }
        else {
            int first = (start+end)/2;
            double ans = (resultant[first]);
            return ans;
        }
        return -1;
    }
};