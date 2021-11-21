/*
Description
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example
Example 1:

Input：{1,3,2,4#2#3,5,6#4#5#6}
Output：{1,3,2,4#2#3,5,6#4#5#6}
Explanation：Pictured above
Example 2:

Input：{1,3,2#2#3}
Output：{1,3,2#2#3}
Explanation：
    1
	 / \
	3   2
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:

    void dfs(DirectedGraphNode* root,string & ans) {
        if(root == NULL)
            return ;
        ans += "[";
        ans += to_string(root->label);
        for(int i = 0; i < root->neighbors.size() ; i++) {
                dfs(root->neighbors[i],ans);
        }
        ans += "]";
        
    }
    UndirectedGraphNode * solve(string& data,int &pos) {
        int num = 0;
            while(data[pos] >= '0' && data[pos] <= '9') {
                num *= 10;
                num += data[pos] - '0';
                pos++;
            }
            UndirectedGraphNode * node =  new UndirectedGraphNode(num);
            while(pos<data.length()) {
                if(data[pos] == '[' )
                    node->neighbors.push_back(solve(data,++pos));
                else if(data[pos] == ']') {
                    pos++;
                    return node;
                }
            }
    }
    string serialize(vector<DirectedGraphNode*> &nodes) {
        string ans;
        if(nodes.size() == 0)
            return ans;
        dfs(nodes[0],ans);
        return ans;
    }
    UndirectedGraphNode * deserialize(string &data) {
        if(data.length() == 0)
            return NULL;
        int pos = 1;
        return solve(data,pos);
    }
  
      
  
};
