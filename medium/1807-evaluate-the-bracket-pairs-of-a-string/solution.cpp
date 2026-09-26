class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Map to store knowledge for O(1) lookups
        unordered_map<string, string> mp;
        for (const auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string result = "";
        int n = s.length();
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                // Extract the key inside the brackets
                string key = "";
                i++; // skip '('
                while (i < n && s[i] != ')') {
                    key += s[i];
                    i++;
                }
                i++; // skip ')'

                // Look up the key in the map
                if (mp.find(key) != mp.end()) {
                    result += mp[key];
                } else {
                    result += '?';
                }
            } else {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};