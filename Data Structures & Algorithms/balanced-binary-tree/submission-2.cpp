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
    bool res = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* cur){
        if (!cur) return -1;
        int left = dfs(cur->left) + 1;
        int right = dfs(cur->right) + 1;
        if (abs(left - right) > 1 ){
            res = false;
        }
        return max(left, right);
    }
};
