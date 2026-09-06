class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        // dp[j] = number of distinct subsequences of s[0..i) equal to t[0..j)
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // empty t can always be formed (one way: pick nothing)

        for (int i = 1; i <= m; i++) {
            // iterate j backwards so dp[j-1] still refers to previous row's value
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return (int)dp[n];
    }
};