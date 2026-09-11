class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        bool seen[1000] = {};
        int ans = 0;

        for (int i = 0; i < digits.size(); i++) {

            // First digit cannot be 0
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < digits.size(); j++) {

                // Cannot use the same copy twice
                if (j == i)
                    continue;

                for (int k = 0; k < digits.size(); k++) {

                    // Cannot use the same copy twice
                    if (k == i || k == j)
                        continue;

                    // Last digit must be even
                    if (digits[k] % 2 != 0)
                        continue;

                    // Create the 3-digit number
                    int num = digits[i] * 100
                           + digits[j] * 10
                           + digits[k];

                    // Count only distinct numbers
                    if (!seen[num]) {
                        seen[num] = true;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};