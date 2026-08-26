# Two Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]


Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


 
Constraints:


	2 <= nums.length <= 104
	-109 <= nums[i] <= 109
	-109 <= target <= 109
	Only one valid answer exists.


 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 66.91%)  
**Memory:** 15 MB (beats 12.31%)  
**Submitted:** 2026-08-26T16:53:32.790Z  

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int,int>mpp;
      int a,more;
      for(int i =0;i<nums.size();i++)
      {
        a = nums[i];
        more = target-a;
        if(mpp.find(more)!=mpp.end())
        {
            return {mpp[more],i};
        }
        mpp[a]=i;
      } 
      return{-1,-1};
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/two-sum/)