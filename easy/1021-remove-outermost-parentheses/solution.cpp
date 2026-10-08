class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char ch : s) {
            if (ch == '(') {
                depth++;

                // Add '(' only if it is NOT the outermost one
                if (depth > 1)
                    ans += ch;
            }
            else {
                // Decrease depth first
                depth--;

                // Add ')' only if it is NOT the outermost one
                if (depth > 0)
                    ans += ch;
            }
        }

        return ans;
    }
};