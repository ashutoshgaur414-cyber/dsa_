class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        sort(s.begin(), s.end());

        do {
            if (s > target) {
                return s;
            }
        } while (next_permutation(s.begin(), s.end()));

        return "";
    }
};