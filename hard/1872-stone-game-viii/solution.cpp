class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> P(n);
        P[0] = stones[0];
        for (int i = 1; i < n; i++)
            P[i] = P[i - 1] + stones[i];

        long long dp = P[n - 1]; // best score diff if it's your turn starting at index n-1
        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, P[i] - dp);
        }
        return (int)dp;
    }
};