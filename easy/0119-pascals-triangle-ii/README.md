# Pascal's Triangle II

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer `rowIndex`, return the `rowIndexth` (**0-indexed**) row of the **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

 

**Example 1:**

```
Input: rowIndex = 3
Output: [1,3,3,1]

```

**Example 2:**

```
Input: rowIndex = 0
Output: [1]

```

**Example 3:**

```
Input: rowIndex = 1
Output: [1,1]

```

 

**Constraints:**

- 0 <= rowIndex <= 33

 

**Follow up:** Could you optimize your algorithm to use only `O(rowIndex)` extra space?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.9 MB (beats 48.33%)  
**Submitted:** 2026-10-07T16:28:34.437Z  

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int >ans;
      long long   x = 1;
      ans.push_back(1);
        for(int i =0;i<rowIndex;i++)
        {
            x = x*(rowIndex-i);
              x = x/(i+1);
            ans.push_back(x);
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/pascals-triangle-ii/)