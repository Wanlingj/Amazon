/*
Description
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

Example
Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23

*/

### 解题思路
Traverse through all nodes and find values between L and R, sum them up to get the final result.
- - -
### 题解代码
```
[[cpp]]
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root node
     * @param L: an integer
     * @param R: an integer
     * @return: the sum
     */
    int res=0;
    int rangeSumBST(TreeNode * root, int L, int R) {
        // write your code here.
        if(root->left){
          rangeSumBST(root->left,L,R);
        }
        if(root->val>=L &&root->val<=R)
            res+=root->val;
        if(root->right){
          rangeSumBST(root->right,L,R);
        }
        return res;
    }
};
```
