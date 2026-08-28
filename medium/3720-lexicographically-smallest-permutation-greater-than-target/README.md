# Lexicographically Smallest Permutation Greater Than Target

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two strings s and target, both having length n, consisting of lowercase English letters.

Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.

A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

 
Example 1:


Input: s = "abc", target = "bba"

Output: "bca"

Explanation:


	The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
	The lexicographically smallest permutation that is strictly greater than target is "bca".



Example 2:


Input: s = "leet", target = "code"

Output: "eelt"

Explanation:


	The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
	The lexicographically smallest permutation that is strictly greater than target is "eelt".



Example 3:


Input: s = "baba", target = "bbaa"

Output: ""

Explanation:


	The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
	None of them is lexicographically strictly greater than target. Therefore, the answer is "".



 
Constraints:


	1 <= s.length == target.length <= 300
	s and target consist of only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.9 MB  
**Submitted:** 2026-08-27T14:57:14.159Z  

```cpp
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        // Count characters of s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Match target from left to right
        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // Cannot match target[i]
            if (freq[x] == 0) {

                // Try a character greater than target[i]
                for (int c = x + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        string ans = target.substr(0, i);

                        ans += char('a' + c);

                        freq[c]--;

                        // Add remaining characters
                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                ans += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return ans;
                    }
                }

                // IMPORTANT:
                // Don't return here.
                // We need to backtrack.
                break;
            }

            // Consume target[i]
            freq[x]--;
        }

        // Backtrack from right to left
        for (int i = target.size() - 1; i >= 0; i--) {

            int x = target[i] - 'a';

            // Return this character to freq
            freq[x]++;

            // Find smallest character greater than target[i]
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + c);

                    freq[c]--;

                    // Remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/)