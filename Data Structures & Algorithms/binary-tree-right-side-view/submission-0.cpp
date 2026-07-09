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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 1; i <= sz; ++i) {
                auto tp = q.front();
                q.pop();
                if (i == sz) ans.push_back(tp->val);
                if (tp->left) q.push(tp->left);
                if (tp->right) q.push(tp->right);
            }
        }

        return ans;
    }
};
