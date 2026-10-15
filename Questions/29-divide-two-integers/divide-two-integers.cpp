class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = true;
        if(dividend >=0 && divisor < 0) {
            sign = false;
        }

        if(dividend < 0 && divisor > 0) {
            sign = false;
        }

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        // divisor = abs(divisor);
        long long ans = 0;

        while(n >= d) {
            int count = 0;
            while(n >= (d << (count+1))) {
                count++;
            }

            ans += (1LL << count);
            n -= (d << count);
        }

        if(ans == (1<<31) && sign) {
            return INT_MAX;
        }

        if(ans == (1<<31) && !sign) {
            return INT_MIN;
        }

        return sign ? ans : -ans;
    }
};