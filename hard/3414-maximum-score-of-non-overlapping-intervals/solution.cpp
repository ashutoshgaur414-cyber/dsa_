class Solution {
public:

    struct State {
        long long score = 0;
        vector<int> idx;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.idx < b.idx;   // lexicographically smaller
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {start, end, weight, original index}
        vector<array<long long, 4>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending point
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a[1] != b[1])
                return a[1] < b[1];

            return a[0] < b[0];
        });

        // prev[i] = number of intervals before i
        // that can be used with interval i
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {

            int lo = 0, hi = i - 1;
            int ans = -1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                // Strictly less because touching boundaries overlap
                if (v[mid][1] < v[i][0]) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            prev[i] = ans;
        }

        // dp[i][k]:
        // first i intervals, using at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; i++) {

            // Option 1: don't take interval i-1
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
            }

            // Option 2: take interval i-1
            for (int k = 1; k <= 4; k++) {

                State take;

                take.score =
                    v[i - 1][2] +
                    dp[prev[i - 1] + 1][k - 1].score;

                take.idx =
                    dp[prev[i - 1] + 1][k - 1].idx;

                take.idx.push_back((int)v[i - 1][3]);

                // Keep indices sorted because answer must be
                // lexicographically compared by original indices
                sort(take.idx.begin(), take.idx.end());

                if (better(take, dp[i][k])) {
                    dp[i][k] = take;
                }
            }
        }

        return dp[n][4].idx;
    }
};