class Solution {
public:
    /**
     * @param A: an array
     * @return: the sum of subarray minimums
     */
//单调栈解决；
//假设从数组的头部遍历，如果后面的数大于前面的数，那么这两个数构成的子数组取得肯定是前面的小的数；
// 如果后面的数小于前面的数，那么子数组就得取后面的数。
// 那么当前元素的贡献就是：
// A[j] * A[j]与其前一个较少的元素之间的距离 * A[j]与其下一个较小元素之间的距离
// 将所有元素的贡献相加即可。
    int sumSubarrayMins(vector<int> &A) {
        // Write your code here.
        // int res = 0, n = A.size(), mod = 1e9 + 7, j, k;
        // stack<int> s;
        // for (int i = 0; i <= n; ++i) {
        //     while (!s.empty() && A[s.top()] > (i == n ? 0 : A[i])) {
        //         j = s.top(), s.pop();
        //         k = s.empty() ? -1 : s.top();
        //         res = (res + A[j] * (i - j) * (j - k)) % mod;
        //     }
        //     s.push(i);
        // }
        // return res;

// Efficient Approach: The general intuition for solution to the problem is to find sum(A[i] * f(i)), where f(i) is the number of subarrays in which A[i] is the minimum.
// In order to find f[i], we need to find out: 
// left[i], the length of strictly larger numbers on the left of A[i], 
// right[i], the length of larger numbers on the right of A[i].
// We make two arrays left[ ] and right[ ] such that: 
// left[i] + 1 equals to the number of subarrays ending with A[i], and A[i] is only single minimum. 
// Similarly, right[i] + 1 equals to the number of subarrays starting with A[i], and A[i] is first minimum.
// Finally, f(i) = (left[i]) * (right[i]), where f[i] equals total number of subarrays in which A[i] is minimum.x


        int n = A.size(),mod = 1e9 + 7;
        int left[n], right[n];
 
    stack<pair<int, int> > s1, s2;
 
    // getting number of element strictly larger
    // than A[i] on Left.
    for (int i = 0; i < n; ++i) {
        int cnt = 1;
 
        // get elements from stack until element
        // greater than A[i] found
        while (!s1.empty() && (s1.top().first) > A[i]) {
            cnt += s1.top().second;
            s1.pop();
        }
 
        s1.push({ A[i], cnt });
        left[i] = cnt;
    }
 
    // getting number of element larger than A[i] on Right.
    for (int i = n - 1; i >= 0; --i) {
        int cnt = 1;
 
        // get elements from stack until element greater
        // or equal to A[i] found
        while (!s2.empty() && (s2.top().first) >= A[i]) {
            cnt += s2.top().second;
            s2.pop();
        }
 
        s2.push({ A[i], cnt });
        right[i] = cnt;
    }
 
    int result = 0;
 
    // calculating required resultult
    for (int i = 0; i < n; ++i)
        result = (result + A[i] * left[i] * right[i])%mod;
 
    return result;
    }
};
