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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;
        int inidx = 0;
        return dfs(preorder, inorder, preidx, inidx, INT_MAX);
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& preidx, int& inidx, int limit){
        if (preidx >= preorder.size()) return nullptr;
        if (inorder[inidx] == limit){
            inidx++;
            return nullptr;
        }
        TreeNode* curnode = new TreeNode(preorder[preidx++]);
        curnode->left = dfs(preorder, inorder, preidx, inidx, curnode->val);
        curnode->right = dfs(preorder, inorder, preidx, inidx, limit);
        return curnode;
    }
};
