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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        reverse(root, root->left);
        reverse(root, root->right);
        root->left = nullptr;
        root->right = nullptr;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        collect(st1, p);
        collect(st2, q);
        TreeNode* res;
        while(!st1.empty() && !st2.empty() && st1.top() == st2.top()){
            res = st1.top();
            st1.pop();
            st2.pop();
        }
        return res;
    }

    void reverse(TreeNode* root, TreeNode* nxt){
        if (!root || !nxt) return;
        TreeNode* leftnxt = nxt->left;
        TreeNode* rightnxt = nxt->right;
        reverse(nxt, leftnxt);
        reverse(nxt, rightnxt);
        nxt->left = root;
        nxt->right = nullptr;
    }

    void collect(stack<TreeNode*>& st, TreeNode* cur){
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
    }
};
