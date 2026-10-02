# Generate Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.

 

**Example 1:**

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

```

**Example 2:**

```
Input: n = 1
Output: ["()"]

```

 

**Constraints:**

- 1 <= n <= 8

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 12.39%)  
**Memory:** 16.1 MB (beats 19.25%)  
**Submitted:** 2026-10-02T13:32:33.461Z  

```cpp
class Solution {
public:
    vector<string> ans;

    void solve(string s, int open, int close, int n) {
        // We have used all brackets
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add opening bracket
        if (open < n) {
            solve(s + "(", open + 1, close, n);
        }

        // Add closing bracket only when valid
        if (close < open) {
            solve(s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)