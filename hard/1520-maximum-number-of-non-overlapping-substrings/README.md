# Maximum Number of Non-Overlapping Substrings

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string `s` of lowercase letters, you need to find the maximum number of **non-empty** substrings of `s` that meet the following conditions:

- The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
- A substring that contains a certain character c must also contain all occurrences of c.

Find *the maximum number of substrings that meet the above conditions*. If there are multiple solutions with the same number of substrings, *return the one with minimum total length. *It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in **any** order.

 

**Example 1:**

```
Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.

```

**Example 2:**

```
Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.

```

 

**Constraints:**

- 1 <= s.length <= 105
- s contains only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 15 ms (beats 50.62%)  
**Memory:** 23.5 MB (beats 43.46%)  
**Submitted:** 2026-09-18T16:37:00.546Z  

```cpp
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';

            if (first[x] == -1)
                first[x] = i;

            last[x] = i;
        }

        vector<pair<int,int>> intervals;

        // Try to create the smallest valid substring
        for (int i = 0; i < s.size(); i++) {

            int c = s[i] - 'a';

            // Only start from the first occurrence
            if (first[c] != i)
                continue;

            int l = i;
            int r = last[c];
            bool valid = true;

            for (int j = l; j <= r; j++) {

                int x = s[j] - 'a';

                // This character appeared before l,
                // so we cannot make a valid substring starting at l
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // We must include ALL occurrences of this character
                r = max(r, last[x]);
            }

            if (valid)
                intervals.push_back({l, r});
        }

        // To get maximum number of non-overlapping intervals,
        // choose intervals with the earliest ending position.
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto &p : intervals) {

            if (p.first > prevEnd) {
                ans.push_back(s.substr(p.first, p.second - p.first + 1));
                prevEnd = p.second;
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)