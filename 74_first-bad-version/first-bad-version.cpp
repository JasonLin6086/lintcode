/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/first-bad-version
@Language: C++
@Datetime: 15-09-05 04:52
*/

/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        if (n==1) return 1;
        int start=1, end=n, mid;
        /*
        while (start+1<end) {
            mid = start + (end-start) / 2;
            if (VersionControl::isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (VersionControl::isBadVersion(start)) {
            return start;
        } else {
            return end;
        }
        */
        while (start < end) {
            mid = start + (end - start)/2;
            if (VersionControl::isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return end;
    }
};

