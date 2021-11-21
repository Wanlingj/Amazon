/*
Description
Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Example
Example 1:

Input：{1,3,2,4#2#3,5,6#4#5#6}
Output：[[1],[3,2,4],[5,6]]
Explanation：Pictured above
Example 2:

Input：{1,3,2#2#3}
Output：[[1],[3,2]]
Explanation：
    1
	 / \
	3   2

*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /**
     * @param root: the tree root
     * @return: the order level of this tree
     */
    queue<UndirectedGraphNode *> q;
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(UndirectedGraphNode* root) {
        // write your code here
        if(root == NULL) return {};
        q.push(root);
        int len = q.size();
        while(! q.empty()){
            vector<int> nums;
            for(int i = 0; i < len; i ++){
                UndirectedGraphNode * p = q.front();
                q.pop();
                nums.push_back(p->label);
                for(int m = 0; m < p->neighbors.size(); m ++){
                    q.push(p->neighbors[m]);
                }
            }
            len = q.size();
            res.push_back(nums);
        }
        return res;
    }
};
