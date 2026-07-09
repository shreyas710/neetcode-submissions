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
    int solve(TreeNode* root, int max_val) {
        if (!root) return 0;
        int cnt = 0;

        if (root->val >= max_val) {
            cnt = 1;
            max_val = root->val;
        }

        cnt += solve(root->left, max_val);
        cnt += solve(root->right, max_val);

        return cnt;
    }

    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }
};
