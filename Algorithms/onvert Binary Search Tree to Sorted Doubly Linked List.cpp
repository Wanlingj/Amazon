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
     * @param root: root of a tree
     * @return: head node of a doubly linked list
     */
    TreeNode * treeToDoublyList(TreeNode * root) {
        // Write your code here.
        if(root == nullptr)
            return nullptr;
        TreeNode* first = nullptr;
        TreeNode* last = nullptr;
        
        treeToDLLUtil(root, &first, &last);
        last->right = first;
        first->left = last;
        return first;
    }
private:
    void treeToDLLUtil(TreeNode* root, TreeNode** first, TreeNode** last){
        if(root == nullptr)
            return;
        treeToDLLUtil(root->left, first, last);
        if(*first == nullptr){
            *first = root;
            *last = root;
        } else {
           (*last)->right = root;
            root->left = *last;
            *last = root;
        }
        treeToDLLUtil(root->right, first, last);
    }
};
