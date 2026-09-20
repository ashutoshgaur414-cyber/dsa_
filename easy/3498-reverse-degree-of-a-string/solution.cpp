class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            // Reverse alphabet position
            int revPos = 'z' - s[i] + 1;

            // Position in string is i + 1
            ans += revPos * (i + 1);
        }

        return ans;
    }
};