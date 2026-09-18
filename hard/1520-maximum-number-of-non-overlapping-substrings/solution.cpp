class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';

            if (first[x] == -1)
                first[x] = i;

            last[x] = i;
        }

        vector<pair<int,int>> intervals;

        // Try to create the smallest valid substring
        for (int i = 0; i < s.size(); i++) {

            int c = s[i] - 'a';

            // Only start from the first occurrence
            if (first[c] != i)
                continue;

            int l = i;
            int r = last[c];
            bool valid = true;

            for (int j = l; j <= r; j++) {

                int x = s[j] - 'a';

                // This character appeared before l,
                // so we cannot make a valid substring starting at l
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // We must include ALL occurrences of this character
                r = max(r, last[x]);
            }

            if (valid)
                intervals.push_back({l, r});
        }

        // To get maximum number of non-overlapping intervals,
        // choose intervals with the earliest ending position.
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto &p : intervals) {

            if (p.first > prevEnd) {
                ans.push_back(s.substr(p.first, p.second - p.first + 1));
                prevEnd = p.second;
            }
        }

        return ans;
    }
};