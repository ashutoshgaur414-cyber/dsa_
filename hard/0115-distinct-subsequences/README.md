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
**Runtime:** 0 ms  
**Memory:** 7.8 MB  
**Submitted:** 2026-09-06T12:49:43.021Z  

```cpp
        for (int i = 1; i <= m; i++) {

        dp[0] = 1; // empty t can always be formed (one way: pick nothing)
        // dp[j] = number of distinct subsequences of s[0..i) equal to t[0..j)
        vector<unsigned long long> dp(n + 1, 0);
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
public:
class Solution {

```

---

[View on LeetCode](https://leetcode.com/problems/distinct-subsequences/)