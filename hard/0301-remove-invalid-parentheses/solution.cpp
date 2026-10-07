class Solution {
public:

    vector<string> ans;

    void dfs(string &s, int start, int lastRemove,
             int leftRem, int rightRem) {

        for (int i = start; i < s.size(); i++) {

            // Don't remove duplicate parentheses
            if (i != start && s[i] == s[i - 1])
                continue;

            // We only remove '(' if leftRem > 0
            // and ')' if rightRem > 0
            if (s[i] == '(' && leftRem == 0)
                continue;

            if (s[i] == ')' && rightRem == 0)
                continue;

            // Remove s[i]
            string temp = s;
            temp.erase(i, 1);

            int newLeft = leftRem;
            int newRight = rightRem;

            if (s[i] == '(')
                newLeft--;
            else
                newRight--;

            dfs(temp, i, i, newLeft, newRight);
        }

        // No removals left -> check validity
        if (leftRem == 0 && rightRem == 0) {

            int balance = 0;

            for (char c : s) {

                if (c == '(')
                    balance++;

                else if (c == ')') {
                    balance--;

                    if (balance < 0)
                        return;
                }
            }

            if (balance == 0)
                ans.push_back(s);
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        for (char c : s) {

            if (c == '(') {
                leftRem++;
            }
            else if (c == ')') {

                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        dfs(s, 0, 0, leftRem, rightRem);

        return ans;
    }
};