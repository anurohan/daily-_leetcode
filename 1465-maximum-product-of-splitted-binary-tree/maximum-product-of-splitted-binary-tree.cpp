class Solution {
public:
    long long total = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    long long findTotal(TreeNode* root) {
        if (!root) return 0;

        return root->val
             + findTotal(root->left)
             + findTotal(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long currSum = root->val + left + right;

        ans = max(ans, currSum * (total - currSum));

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        total = findTotal(root);

        dfs(root);

        return ans % MOD;
    }
};