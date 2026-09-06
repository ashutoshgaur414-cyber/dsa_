# Distinct Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 
Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit


Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag

 
Constraints:


	1 <= s.length, t.length <= 1000
	s and t consist of English letters.

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 96.20%)  
**Memory:** 9 MB (beats 86.32%)  
**Submitted:** 2026-09-06T12:49:48.868Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/distinct-subsequences/)