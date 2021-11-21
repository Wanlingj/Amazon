/*Description
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node. The answer can be returned in any order.
Example
Example 1:

Input:
{3,5,1,6,2,0,8,#,#,7,4}
5
2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Example 2

Input:
{1,2,3,4}
2
1

Output: [1,4]

Explanation:
The binary tree is like this:
    1
   / \
  2   3
 /   
4   
The node 1 and 4 is 1 away from 2.
*/
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
     * @param root: the root of the tree
     * @param target: the target
     * @param K: the given K
     * @return: All Nodes Distance K in Binary Tree
     */
   
    int findTargetChild(TreeNode* root, TreeNode* target, int K, vector<int>& distanceKNode)
    {
        if(root == nullptr) return -1;
        else if(root == target)
        {
            findDistanceKFromChildren(root, K, distanceKNode);
            //found target child return 0
            return 0;
        }
        else
        {
            int lt = findTargetChild(root->left, target, K, distanceKNode);
            int rt = findTargetChild(root->right, target, K, distanceKNode);

            if(lt != -1)
            {
                if(lt + 1 == K)
                {
                    distanceKNode.push_back(root->val);
                }
                else
                {
                    findDistanceKFromChildren(root->right, K-lt-2, distanceKNode);
                }
                return lt+1;
            }
            else if(rt != -1)
            {
                if(rt +1== K)
                {
                    distanceKNode.push_back(root->val);
                }
                else
                {
                    findDistanceKFromChildren(root->left, K-rt-2, distanceKNode);
                }
                return rt +1;
            }
            else
            {
                return -1;
            }
        }
    }
    void findDistanceKFromChildren(TreeNode* root, int K, vector<int>& distanceKNode)
    {
        if(root == nullptr) return;
        if(K == 0)
        {
            distanceKNode.push_back(root->val);
        }

        findDistanceKFromChildren(root->left, K-1, distanceKNode);
        findDistanceKFromChildren(root->right, K-1, distanceKNode);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> distanceKNode;
        findTargetChild(root, target, K, distanceKNode);

        return distanceKNode;
    }
};
