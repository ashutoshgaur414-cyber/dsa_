# Count Commas in Range II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer n.

Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

In standard formatting:


	A comma is inserted after every three digits from the right.
	Numbers with fewer than 4 digits contain no commas.


 
Example 1:


Input: n = 1002

Output: 3

Explanation:

The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.


Example 2:


Input: n = 998

Output: 0

Explanation:

​​​​​​​All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.


 
Constraints:


	1 <= n <= 1015

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9 MB (beats 84.80%)  
**Submitted:** 2026-09-09T13:29:51.963Z  

```cpp
class Solution {
public:
    long long countCommas(long long n) {


if(n<1000)
{
    return 0;
}
long ans = 0;
if(n>=1000)
{
    ans = ans +(n-999);
}
if(n>=1000000)
{
    ans +=(n-999999);
}
if(n>=1000000000)
{
    ans +=(n-999999999);
}
if(n>=1000000000000L)
{
    ans += (n-999999999999L);
}
if(n>=1000000000000000L)
{
    ans +=(n-999999999999999);
}

return ans;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-commas-in-range-ii/)