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
    int ans = 0;

    // returns {sum, count}
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        // Get information from left subtree
        pair<int, int> left = dfs(root->left);

        // Get information from right subtree
        pair<int, int> right = dfs(root->right);

        // Calculate current subtree
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Check average
        if (root->val == sum / count) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};