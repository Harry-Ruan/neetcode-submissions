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
    int res = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, -INT_MAX);
        return res;
    }

    void dfs(TreeNode* cur, int pathmax){
        if (!cur) return;
        if (cur->val >= pathmax){
            pathmax = cur->val;
            res++;
        }
        dfs(cur->left, pathmax);
        dfs(cur->right, pathmax);
    }
};
