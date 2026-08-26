class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < s.size(); right++)
        {
            // Add current character
            if (s[right] == '1')
                ones++;

            // If we have more than k ones,
            // move left until we have k ones
            while (ones > k)
            {
                if (s[left] == '1')
                    ones--;

                left++;
            }

            // Remove unnecessary zeroes from the left
            while (left < right && s[left] == '0')
            {
                left++;
            }

            // Now we have exactly k ones
            if (ones == k)
            {
                string current = s.substr(left, right - left + 1);

                // First valid answer
                if (ans == "")
                {
                    ans = current;
                }
                // Shorter answer
                else if (current.size() < ans.size())
                {
                    ans = current;
                }
                // Same length -> lexicographically smaller
                else if (current.size() == ans.size() && current < ans)
                {
                    ans = current;
                }
            }
        }

        return ans;
    }
};