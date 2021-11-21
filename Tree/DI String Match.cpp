/*
Description
Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]

Example
Example 1:

Input："IDID"
Output：[0,4,1,3,2]
Explanation：according to "IDID",0<4,4>1,1<3,3>2.
Example 2:

Input："III"
Output：[0,1,2,3]
Explanation：according to "III",0<1,1<2,2<3.

*/




class Solution {
public:
    vector<int> diStringMatch(string &S) {
        int max = S.length();
        int len = S.length();
        int min = 0;
        vector<int> ans(max + 1);
        for(int i = 0;i < len;i++){
            if(S[i] == 'D')  {
                ans[i] = max--;
            }
            else{
                ans[i] = min++;
            }
        }
        ans[len] = min;
        return ans;
    }
};
