# Check if There Is a Valid Parentheses String Path

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

A parentheses string is a **non-empty** string consisting only of `'('` and `')'`. It is **valid** if **any** of the following conditions is **true**:

- It is ().
- It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
- It can be written as (A), where A is a valid parentheses string.

You are given an `m x n` matrix of parentheses `grid`. A **valid parentheses string path** in the grid is a path satisfying **all** of the following conditions:

- The path starts from the upper left cell (0, 0).
- The path ends at the bottom-right cell (m - 1, n - 1).
- The path only ever moves down or right.
- The resulting parentheses string formed by the path is valid.

Return `true` *if there exists a **valid parentheses string path** in the grid.* Otherwise, return `false`.

 

**Example 1:**

```
Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.

```

**Example 2:**

```
Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.

```

 

**Constraints:**

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- grid[i][j] is either '(' or ')'.

## Solution

**Language:** C++  
**Runtime:** 170 ms (beats 43.23%)  
**Memory:** 135.9 MB (beats 34.59%)  
**Submitted:** 2026-09-29T19:50:38.156Z  

```cpp
class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int balance,
               vector<vector<char>>& grid) {

        if (balance < 0)
            return false;

        if (i >= m || j >= n)
            return false;

        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool down = solve(i + 1, j, balance, grid);
        bool right = solve(i, j + 1, balance, grid);

        return dp[i][j][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // Start must be '('
        if (grid[0][0] != '(')
            return false;

        // End must be ')'
        if (grid[m - 1][n - 1] != ')')
            return false;

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(m + n + 1, -1)
        ));

        return solve(0, 0, 0, grid);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)