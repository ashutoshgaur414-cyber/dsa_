# Find Two Non-overlapping Sub-arrays Each With Target Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array of integers `arr` and an integer `target`.

You have to find **two non-overlapping sub-arrays** of `arr` each with a sum equal `target`. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is **minimum**.

Return *the minimum sum of the lengths* of the two required sub-arrays, or return `-1` if you cannot find such two sub-arrays.

 

**Example 1:**

```
Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.

```

**Example 2:**

```
Input: arr = [7,3,4,7], target = 7
Output: 2
Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.

```

**Example 3:**

```
Input: arr = [4,3,2,6,2,3,4], target = 6
Output: -1
Explanation: We have only one sub-array of sum = 6.

```

 

**Constraints:**

- 1 <= arr.length <= 105
- 1 <= arr[i] <= 1000
- 1 <= target <= 108

## Solution

**Language:** C++  
**Runtime:** 8 ms (beats 70.62%)  
**Memory:** 88.9 MB (beats 67.53%)  
**Submitted:** 2026-09-17T14:25:53.958Z  

```cpp
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX); // best[i] = length of shortest valid subarray ending at or before i
        int ans = INT_MAX;
        int left = 0, sum = 0;
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            if (sum == target) {
                int currLen = right - left + 1;
                
                // If there's a valid subarray ending before 'left', combine them
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, best[left - 1] + currLen);
                }
                
                // Update best[right] with the shortest length seen so far ending at/by 'right'
                best[right] = min((right > 0 ? best[right - 1] : INT_MAX), currLen);
            } else {
                best[right] = (right > 0 ? best[right - 1] : INT_MAX);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)