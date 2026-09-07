/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return (check(root->left, root->val, -1000000001) && check(root->right, 1000000001, root->val)); 
    }

    bool check(TreeNode* cur, int max, int min){
        if (!cur) return true;
        if (cur->val >= max || cur->val <= min) return false;
        return (check(cur->left, cur->val, min) && check(cur->right, max, cur->val));
    }
};
