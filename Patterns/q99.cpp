#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    while (s.length() > 1) {
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            int sum = 0;
            for (int j = i; j < s.length(); j++) {
                sum = sum + (s[j] - '0');
                total += sum;
            }
        }
        s = to_string(total);
    }
    return s[0] - '0';
}

int main() {
    string s;
    cin >> s;

    cout << solve(s) << endl;
}