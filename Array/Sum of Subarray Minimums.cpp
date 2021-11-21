/*
Description
Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

Example
Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
Example 2:

Input: [95,58,46,67,100]
Output: 859
Explanation: Subarrays are [95], [58], [46], [67], [100], [98,58], [58,46], [46,67], [67,100], [95,58,67],[46,67,100],[95,58,46,67],[58,46,67,100],[95,58,46,67,100]. 
Minimums are 95, 58, 46, 67, 100, 58, 46, 46, 67, 46, 46, 46, 46, 46, 46.  Sum is 859.


*/


class Solution {
public:
    /**
     * @param A: an array
     * @return: the sum of subarray minimums
     */
    int sumSubarrayMins(vector<int> &A) {
        // Write your code here.
        int res = 0, n = A.size(), mod = 1e9 + 7, j, k;
        stack<int> s;
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && A[s.top()] > (i == n ? 0 : A[i])) {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();
                res = (res + A[j] * (i - j) * (j - k)) % mod;
            }
            s.push(i);
        }
        return res;
    }
};
