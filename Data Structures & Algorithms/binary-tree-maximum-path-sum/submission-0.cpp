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
    int maxPathSum(TreeNode* root) {
        map<TreeNode*, int> paths;
        int maximum = -INT_MAX;
        dfs(root, maximum);
        return maximum;
    }

    int dfs(TreeNode* cur, int& maximum){
        if (!cur) return 0;
        int leftmax = dfs(cur->left, maximum);
        int rightmax = dfs(cur->right, maximum);
        int maxpath = max(leftmax + cur->val, max(rightmax + cur->val, cur->val));
        maximum = max(leftmax + rightmax + cur->val, max(maxpath, maximum));
        return maxpath;
    }
};
