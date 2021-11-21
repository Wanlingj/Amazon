/*
Description
Given an array arr and a nonnegative integer k, you need to find a continuous array from this array so that the sum of this array is k. Output the length of this array. If there are multiple such substrings, return the one with the minimum ending position; if there are multiple answers, return the one with the minimum starting position. If no such subarray is found, -1 is returned.

Example

Example 1 :
Input：arr=[1,2,3,4,5] ，k=5
Output：2
Explanation:
In this array, the earliest contiguous substring is [2,3].

Example 2 :
Input：arr=[3,5,7,10,2] ，k=12
Output：2
Explanation:
In this array, the earliest consecutive concatenated substrings with a sum of 12 are [5,7].

*/

class Solution {
public:
    /**
     * @param arr: The array 
     * @param k: the sum 
     * @return: The length of the array
     */
    int searchSubarray(vector<int> &arr, int k) {
        // Write your code here
        // sum and location map
        map <int, int> mp;
        int l = arr.size();
        int sum = 0;
        int i;
        mp.clear();
        mp[0] = 0;
        for (i = 0; i < l; i++) {
            sum += arr[i];
            if (mp.find(sum - k) != mp.end()) {
                return (i + 1 - mp[sum - k]);
            }
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i + 1;
            }
        }
        return -1;
    }
};
