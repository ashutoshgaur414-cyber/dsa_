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

            // If target[i] is not available,
            // we cannot keep matching.
            if (freq[x] == 0) {

                // Find smallest character greater than target[i]
                for (int c = x + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        string ans = target.substr(0, i);

                        ans += char('a' + c);

                        freq[c]--;

                        // Add remaining characters in sorted order
                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                ans += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return ans;
                    }
                }

                // We cannot make anything greater
                return "";
            }

            // Use this character
            freq[x]--;
        }

        // target itself can be formed.
        // Now we need to make it slightly greater.
        // Go from right to left.

        for (int i = target.size() - 1; i >= 0; i--) {

            // Return target[i] to available characters
            int x = target[i] - 'a';
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