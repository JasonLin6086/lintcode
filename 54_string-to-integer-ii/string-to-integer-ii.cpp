/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/string-to-integer-ii
@Language: C++
@Datetime: 15-09-23 06:23
*/

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        if (str.empty()) {
            return 0;
        }

        int ans = 0;
        int sign = 1;
        int i = 0;

        // Skip ' '.
        while (str[i] == ' ') {
            ++i;
        }

        // Parse sign.
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            sign = -1;
            ++i;
        }

        // Compute integer.
        for (; i < str.length() && isdigit(str[i]); ++i) {
            if (ans > (INT_MAX - (str[i] - '0')) / 10 ||
                ((str[i] - '0') == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) { 
                    return sign > 0 ? INT_MAX : INT_MIN;
            }
            ans *= 10;
            ans += str[i] - '0';
        }

        ans *= sign;
        return ans;
    }
};
