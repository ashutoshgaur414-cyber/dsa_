# Maximum Score of Non-overlapping Intervals

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. Interval i starts at position li and ends at ri, and has a weight of weighti. You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.

Return the lexicographically smallest array of at most 4 indices from intervals with maximum score, representing your choice of non-overlapping intervals.

Two intervals are said to be non-overlapping if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.

 
Example 1:


Input: intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]

Output: [2,3]

Explanation:

You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.


Example 2:


Input: intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]]

Output: [1,3,5,6]

Explanation:

You can choose the intervals with indices 1, 3, 5, and 6 with respective weights of 7, 6, 3, and 5.


 
Constraints:


	1 <= intevals.length <= 5 * 104
	intervals[i].length == 3
	intervals[i] = [li, ri, weighti]
	1 <= li <= ri <= 109
	1 <= weighti <= 109

## Solution

**Language:** C++  
**Runtime:** 861 ms (beats 55.43%)  
**Memory:** 319.7 MB (beats 46.74%)  
**Submitted:** 2026-09-12T16:11:38.049Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/)