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