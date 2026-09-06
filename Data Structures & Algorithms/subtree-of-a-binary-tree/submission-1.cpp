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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> pq;
        pq.push(root);
        bool res = false;
        while(!pq.empty()){
            int sz = pq.size();
            for (int i = 0; i < sz; i++){
                TreeNode* cur = pq.front();
                pq.pop();
                if (cur->val == subRoot->val){
                    res = (res || isSameTree(cur, subRoot));
                }
                if (cur->left) pq.push(cur->left);
                if (cur->right) pq.push(cur->right);
            }
        }
        return res;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if ((p && q) && p->val == q->val){
            bool res = (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
            return res;
        }
        return false;
    }
};
