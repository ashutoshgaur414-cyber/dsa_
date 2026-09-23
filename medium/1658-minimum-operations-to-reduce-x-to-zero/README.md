# Minimum Operations to Reduce X to Zero

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.

Return *the **minimum number** of operations to reduce *`x` *to **exactly*** `0` *if it is possible**, otherwise, return *`-1`.

 

**Example 1:**

```
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

```

**Example 2:**

```
Input: nums = [5,6,7,8,9], x = 4
Output: -1

```

**Example 3:**

```
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

```

 

**Constraints:**

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 104
- 1 <= x <= 109

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 46.25%)  
**Memory:** 102.3 MB (beats 65.24%)  
**Submitted:** 2026-09-23T14:01:41.700Z  

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int total = 0;
        for(int num : nums) {
            total += num;
        }

        int target = total - x;

        // If target is 0, remove everything
        if(target == 0)
            return nums.size();

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        for(int right = 0; right < nums.size(); right++) {
            
            sum += nums[right];

            while(left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            if(sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if(maxLen == -1)
            return -1;

        return nums.size() - maxLen;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)