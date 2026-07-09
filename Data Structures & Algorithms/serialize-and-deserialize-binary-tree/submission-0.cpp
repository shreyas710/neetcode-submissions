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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "X,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.

    TreeNode* solve(queue<string>& q) {
        auto tp = q.front();
        q.pop();
        if (tp == "X") return nullptr;

        TreeNode* root = new TreeNode(stoi(tp));
        root->left = solve(q);
        root->right = solve(q);
        return root;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string tmp = "";
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == ',') {
                q.push(tmp);
                tmp = "";
                continue;
            }
            tmp += data[i];
        }

        if (tmp.size() > 0) q.push(tmp);

        return solve(q);
    }
};
