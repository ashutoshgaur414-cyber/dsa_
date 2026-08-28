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