        for (int i = 1; i <= m; i++) {

        dp[0] = 1; // empty t can always be formed (one way: pick nothing)
        // dp[j] = number of distinct subsequences of s[0..i) equal to t[0..j)
        vector<unsigned long long> dp(n + 1, 0);
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
public:
class Solution {
