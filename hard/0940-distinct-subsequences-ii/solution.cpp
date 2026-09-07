class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // empty subsequence, used as base case
        vector<int> last(26, -1); // last index (in dp array) where char was seen

        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];
            dp[i] = (2 * dp[i - 1]) % MOD;
            if (last[c - 'a'] != -1) {
                dp[i] = (dp[i] - dp[last[c - 'a'] - 1] + MOD) % MOD;
            }
            last[c - 'a'] = i;
        }

        return (dp[n] - 1 + MOD) % MOD; // subtract the empty subsequence
    }
};