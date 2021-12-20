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
