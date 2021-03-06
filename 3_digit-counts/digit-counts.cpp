/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/digit-counts
@Language: C++
@Datetime: 15-09-22 16:25
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int result = 0;
        int base = 1;
        while (n/base > 0) {
            int cur = (n/base)%10;
            int low = n - (n/base) * base;
            int high = n/(base * 10);

            if (cur == k) {
                result += high * base + low + 1;
            } else if (cur < k) {
                result += high * base;
            } else {
                result += (high + 1) * base;
            }
            base *= 10;
        }
        return result;
    }
};
