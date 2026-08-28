# Lexicographically Smallest Palindromic Permutation Greater Than Target

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given two strings s and target, each of length n, consisting of lowercase English letters.

Return the lexicographically smallest string that is both a palindromic permutation of s and strictly greater than target. If no such permutation exists, return an empty string.

 
Example 1:


Input: s = "baba", target = "abba"

Output: "baab"

Explanation:


	The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
	The lexicographically smallest permutation that is strictly greater than target is "baab".



Example 2:


Input: s = "baba", target = "bbaa"

Output: ""

Explanation:


	The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
	None of them is lexicographically strictly greater than target. Therefore, the answer is "".



Example 3:


Input: s = "abc", target = "abb"

Output: ""

Explanation:

s has no palindromic permutations. Therefore, the answer is "".


Example 4:


Input: s = "aac", target = "abb"

Output: "aca"

Explanation:


	The only palindromic permutation of s is "aca".
	"aca" is strictly greater than target. Therefore, the answer is "aca".



 
Constraints:


	1 <= n == s.length == target.length <= 300
	s and target consist of only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.1 MB  
**Submitted:** 2026-08-28T07:52:45.698Z  

```cpp
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                mid = 'a' + i;
            }
        }

        // More than one odd frequency -> impossible
        if (odd > 1) {
            return "";
        }

        // Build counts for LEFT HALF
        vector<int> half(26, 0);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int m = n / 2;

        // Function to make palindrome from left half
        auto makePalindrome = [&](string left) {

            string ans = left;

            if (n % 2 == 1) {
                ans += mid;
            }

            reverse(left.begin(), left.end());
            ans += left;

            return ans;
        };

        // Try constructing the left half
        string left = "";

        for (int pos = 0; pos < m; pos++) {

            bool found = false;

            // Try smallest possible character
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Choose this character
                half[c]--;
                left.push_back('a' + c);

                // Put remaining characters in smallest order
                string temp = left;

                for (int x = 0; x < 26; x++) {
                    temp += string(half[x], 'a' + x);
                }

                // Construct palindrome
                string candidate = makePalindrome(temp);

                // If this choice can produce a palindrome > target
                if (candidate > target) {
                    found = true;
                    break;
                }

                // Undo choice
                left.pop_back();
                half[c]++;
            }

            if (!found) {
                return "";
            }
        }

        string answer = makePalindrome(left);

        if (answer > target)
            return answer;

        return "";
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/)