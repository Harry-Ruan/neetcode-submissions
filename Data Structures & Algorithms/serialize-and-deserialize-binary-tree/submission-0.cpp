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

class Codec {
public: 

    // Encodes a tree to a single string. // L2#
    string serialize(TreeNode* root) {
        string res = DFS(root);
        return res;
    }

    string DFS(TreeNode* cur){
        if (!cur) return "N,";
        return to_string(cur->val) + "," + DFS(cur->left) + DFS(cur->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        TreeNode* root = DFS2(data, idx);
        return root;
    }

    TreeNode* DFS2(string& data, int& idx){
        int start = idx;
        while (idx < data.size() && data[idx] != ',') {
            idx++;
        }
    string valStr = data.substr(start, idx - start);
        idx++; 

        if (valStr == "N") return nullptr;

        TreeNode* cur = new TreeNode(stoi(valStr));
    
        
    cur->left = DFS2(data, idx);
    cur->right = DFS2(data, idx);

    return cur;
    }
};
