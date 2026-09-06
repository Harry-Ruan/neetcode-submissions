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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int res = -1;
        DFS(root, k, cnt, res);
        return res;
    }
    // inorder
    void DFS(TreeNode* cur, int k, int& cnt, int& res){
        if (!cur){
            return;
        }
        if (cnt > k) return;
        DFS(cur->left, k, cnt, res);
        cnt++;
        if (cnt == k){
            res = cur->val;
            return;
        }
        DFS(cur->right, k, cnt, res);
    }
};
