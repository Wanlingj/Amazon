/*
https://www.lintcode.com/problem/1890/description?_from=problem_tag&fromId=undefined
*/
class Solution {
public:
    /**
     * @param str: the pattern 
     * @return: the minimum number
     */
    string formMinimumNumber(string &str) {
        // Write your code here.
        int n = str.length(); 
        string ans(n+1, ' ');  
        int count = 1;   
        for (int i = 0; i <= n; i++)  
        {  
            if (i == n || str[i] == 'I') 
            { 
                for (int j = i - 1 ; j >= -1 ; j--) 
                { 
                    ans[j + 1] = '0' + count++; // reversly increasing = decreasing
                    if(j >= 0 && str[j] == 'I') 
                        break; 
                } 
            } 
        } 
        return ans; 
    }
};
