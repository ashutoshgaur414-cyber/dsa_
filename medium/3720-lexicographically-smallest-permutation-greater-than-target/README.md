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
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.8 MB (beats 90.45%)  
**Submitted:** 2026-08-27T14:57:19.272Z  

```cpp
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        // Count characters of s
        for (char c : s) {
            freq[c - 'a']++;
        }

        int n = s.size();

        // Try to match target from left to right
        int i;

        for (i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Cannot match this character
            if (freq[x] == 0) {
                break;
            }

            freq[x]--;
        }

        // Case 1:
        // We could not match target completely
        if (i < n) {

            // First try to make position i greater
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

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

            // Now backtrack through characters
            // that WERE actually consumed
            for (int j = i - 1; j >= 0; j--) {

                int x = target[j] - 'a';

                // Return target[j]
                freq[x]++;

                // Find smallest character greater than target[j]
                for (int c = x + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        string ans = target.substr(0, j);

                        ans += char('a' + c);

                        freq[c]--;

                        // Add remaining characters
                        for (int k = 0; k < 26; k++) {
                            while (freq[k] > 0) {
                                ans += char('a' + k);
                                freq[k]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // Case 2:
        // target itself can be formed
        // Need to find the next greater permutation

        for (int j = n - 1; j >= 0; j--) {

            int x = target[j] - 'a';

            // Return target[j]
            freq[x]++;

            // Find smallest character greater than target[j]
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = target.substr(0, j);

                    ans += char('a' + c);

                    freq[c]--;

                    // Add remaining characters
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
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