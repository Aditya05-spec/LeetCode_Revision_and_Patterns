class Solution {
private:
    void solve(string &s , int index , long long &ans) {
        //Base case
        if(index >= s.length()) {
            return;
        }

        char ch = s[index];
        if(ch >= '0' && ch <= '9') {
            int number = ch - '0';
            ans = ans*10 + number;
        }
        else {
            return;
        }

        if(ans > INT_MAX) {
            return;
        }

        solve(s , index+1 , ans);

    }

public:
    int myAtoi(string s) {
        long long ans = 0;
        int index = 0;
        int sign = 1;

        while(s[index] == ' ' && index < s.length()) {
            index++;
        }

        if(index < s.length() && s[index] == '-' || s[index] == '+') {
            sign = (s[index] == '-')? -1 : 1;
            index++;
        }

        solve(s , index , ans);
        ans *= sign;

        if (ans < INT_MIN) return INT_MIN;
        if (ans > INT_MAX) return INT_MAX;

        return static_cast<int>(ans);
    }
};