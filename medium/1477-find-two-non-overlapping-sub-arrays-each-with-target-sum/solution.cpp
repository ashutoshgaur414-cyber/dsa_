class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX); // best[i] = length of shortest valid subarray ending at or before i
        int ans = INT_MAX;
        int left = 0, sum = 0;
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            if (sum == target) {
                int currLen = right - left + 1;
                
                // If there's a valid subarray ending before 'left', combine them
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, best[left - 1] + currLen);
                }
                
                // Update best[right] with the shortest length seen so far ending at/by 'right'
                best[right] = min((right > 0 ? best[right - 1] : INT_MAX), currLen);
            } else {
                best[right] = (right > 0 ? best[right - 1] : INT_MAX);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};