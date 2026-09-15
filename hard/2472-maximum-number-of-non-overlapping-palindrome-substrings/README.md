# Maximum Number of Non-overlapping Palindrome Substrings

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `s` and a **positive** integer `k`.

Select a set of **non-overlapping** substrings from the string `s` that satisfy the following conditions:

- The length of each substring is at least k.
- Each substring is a palindrome.

Return *the **maximum** number of substrings in an optimal selection*.

A **substring** is a contiguous sequence of characters within a string.

 

**Example 1:**

```
Input: s = "abaccdbbd", k = 3
Output: 2
Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.

```

**Example 2:**

```
Input: s = "adbcda", k = 2
Output: 0
Explanation: There is no palindrome substring of length at least 2 in the string.

```

 

**Constraints:**

- 1 <= k <= s.length <= 2000
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 173 ms (beats 45.55%)  
**Memory:** 19.3 MB (beats 58.11%)  
**Submitted:** 2026-09-15T14:52:52.726Z  

```cpp
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        // isPal[i][j]: s[i..j] inclusive is palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) isPal[i][i] = true;
        for (int i = 0; i + 1 < n; i++) isPal[i][i+1] = (s[i] == s[i+1]);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                isPal[i][j] = (s[i] == s[j]) && isPal[i+1][j-1];
            }
        }
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1]; // don't end a substring at position i-1
            
            // try substring of length k ending here
            if (i >= k) {
                int start = i - k;
                if (isPal[start][i-1]) {
                    dp[i] = max(dp[i], dp[start] + 1);
                }
            }
            // try substring of length k+1 ending here
            if (i >= k + 1) {
                int start = i - (k + 1);
                if (isPal[start][i-1]) {
                    dp[i] = max(dp[i], dp[start] + 1);
                }
            }
        }
        
        return dp[n];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/)