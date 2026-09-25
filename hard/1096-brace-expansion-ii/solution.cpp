class Solution {
public:
    set<string> dfs(string &s, int &i) {
        set<string> res;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++; // skip {

                set<string> inside = dfs(s, i);
                i++; // skip }

                // concatenate cur × inside
                set<string> temp;

                for (string a : cur) {
                    for (string b : inside) {
                        temp.insert(a + b);
                    }
                }

                cur = temp;
            }

            else if (s[i] == ',') {
                // union: save current part
                for (string x : cur)
                    res.insert(x);

                cur = {""};
                i++;
            }

            else {
                // single character
                set<string> temp;

                for (string x : cur) {
                    temp.insert(x + s[i]);
                }

                cur = temp;
                i++;
            }
        }

        // add last part
        for (string x : cur)
            res.insert(x);

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = dfs(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};