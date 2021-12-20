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
     * @param numbers: the given list
     * @param node1: the given node1
     * @param node2: the given node2
    * @return: the distance between two nodes
     */
     
    TreeNode* insert(TreeNode* root, int node){
        if (root == NULL){
            return new TreeNode(node);
        }
        if (root->val > node){
            root->left = insert(root->left, node);
        }
        else if (root->val < node){
            root->right = insert(root->right, node);
        }
        return root;
    } 
     
    TreeNode build(vector<int> &numbers){
        TreeNode root = TreeNode(numbers[0]);
        int len = numbers.size();
        for (int i = 1; i < len; i++){
           insert(&root, numbers[i]);
        }
        return root;
    }
    
    bool check(vector<int> &numbers, int node1, int node2){
        bool flag1 = false, flag2 = false;
        for (auto &i: numbers){
            if (i == node1){
                flag1 = true;
            }
            if (i == node2){
                flag2 = true;
            }
        }
        return (flag1 && flag2);
    }
    
    int findDis(TreeNode* root, int node) {
        int dis = 0;
        while (root->val != node) {
            dis ++;
            if (root->val > node) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return dis;
    }
    
    int bstDistance(vector<int> &numbers, int node1, int node2) {
        if (numbers.size() < 2){
            return -1;
        }
        if (!check(numbers, node1, node2)){
            return -1;
        }
        TreeNode root = build(numbers);
        while (node1 > root.val && node2 > root.val || node1 < root.val && node2 < root.val) {
            if (node1 > root.val && node2 > root.val) {
                root = *root.right;
            } else {
                root = *root.left;
            }
            
        }
        return findDis(&root, node1) + findDis(&root, node2);
    }
};

