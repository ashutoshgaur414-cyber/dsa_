# Majority Element

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

 
Constraints:


	n == nums.length
	1 <= n <= 5 * 104
	-109 <= nums[i] <= 109
	The input is generated such that a majority element will exist in the array.


 
Follow-up: Could you solve the problem in linear time and in O(1) space?

## Solution

**Language:** C++  
**Runtime:** 2360 ms (beats 5.00%)  
**Memory:** 28.2 MB (beats 44.61%)  
**Submitted:** 2026-09-01T14:41:19.511Z  

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
    
        for(int val : nums)
        {
            int count = 0;
            for(int el: nums)
            {
                if(el == val)
                {
                    count ++;
                }
            }
            if(count>n/2)
            {
                return val;
            }
        }
        return -1;
    
}

};
```

---

[View on LeetCode](https://leetcode.com/problems/majority-element/)