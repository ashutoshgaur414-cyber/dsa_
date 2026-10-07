# Pascal's Triangle

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

 

**Example 1:**

```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

```

**Example 2:**

```
Input: numRows = 1
Output: [[1]]

```

 

**Constraints:**

- 1 <= numRows <= 30

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.8 MB (beats 9.32%)  
**Submitted:** 2026-10-07T16:17:24.245Z  

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i =1;i<=numRows;i++)
        {
            long long a = 1;
            vector<int>ansrow;
            ansrow.push_back(1);
            for(int c = 1;c<i;c++)
            {
                a= a *(i-c);
                a = a/(c);
            ansrow.push_back(a);
            }
            ans.push_back(ansrow);
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/pascals-triangle/)