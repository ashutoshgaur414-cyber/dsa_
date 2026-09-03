class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mn = *min_element(nums1.begin(), nums1.end());

        // If minimum is odd, we can make everything odd
        if (mn % 2 != 0)
            return true;

        // Minimum is even, so every element must already be even
        for (int x : nums1) {
            if (x % 2 != 0)
                return false;
        }

        return true;
    }
};