class Solution {
private:
    static bool comparator(vector<int> a , vector<int> b) {
        if(a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , comparator);
        vector<vector<int> > checkInterval;
        checkInterval.push_back(intervals[0]);
        int count = 0;
        for(int i=1 ; i<intervals.size() ; i++) {
            vector<int> element = checkInterval.back();
            int second = element[1];
            int first = intervals[i][0];

            if(second > first) {
                count++;

                if(intervals[i][1] < second) {
                    checkInterval.back() = intervals[i];
                }
                continue;
            }
            checkInterval.push_back(intervals[i]);
        } 
        return count;
    }
};