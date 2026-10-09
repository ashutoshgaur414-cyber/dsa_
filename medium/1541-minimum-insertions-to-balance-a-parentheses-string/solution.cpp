
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                // If the next character is also ')',
                // we have a pair of closing parentheses.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    // Insert one ')' to complete the pair.
                    ans++;
                }

                // Match the closing pair with an opening '('.
                if (open > 0) {
                    open--;
                } 
                else {
                    // No opening '(' exists, so insert one.
                    ans++;
                }
            }
        }

        // Each remaining '(' needs two ')'.
        ans += open * 2;

        return ans;
    }
};

