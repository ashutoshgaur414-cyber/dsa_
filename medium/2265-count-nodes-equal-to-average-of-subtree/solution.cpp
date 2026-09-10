        // Calculate current subtree
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Check average
        if (root->val == sum / count) {
            ans++;
        }


        pair<int, int> right = dfs(root->right);
        // Get information from right subtree

        pair<int, int> left = dfs(root->left);
        // Get information from left subtree

        }
            return {0, 0};
