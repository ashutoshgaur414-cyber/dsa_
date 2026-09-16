# Set Matrix Zeroes

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it in place.

 

**Example 1:**

```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

```

**Example 2:**

```
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

```

 

**Constraints:**

- m == matrix.length
- n == matrix[0].length
- 1 <= m, n <= 200
- -231 <= matrix[i][j] <= 231 - 1

 

**Follow up:**

- A straightforward solution using O(mn) space is probably a bad idea.
- A simple improvement uses O(m + n) space, but still not the best solution.
- Could you devise a constant space solution?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 20.9 MB (beats 55.82%)  
**Submitted:** 2026-09-16T15:21:31.072Z  

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      
      int  row = matrix.size();
      int col = matrix[0].size();
      vector<int>r(row,1);
      vector<int>c(col,1);
      for(int j =0;j<col;j++)
      {
        for(int i =0;i<row;i++)
        {
            if(matrix[i][j]==0)
            {
                r[i]=0;
                c[j]=0;
            }
        }
      }

      for(int j =0;j<col;j++)
      {
        for(int i =0;i<row;i++)
        {
            if(r[i]==0 || c[j]==0)
            {
               matrix[i][j]=0;
            }
        }

      }
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/set-matrix-zeroes/)