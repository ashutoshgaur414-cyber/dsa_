class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int sum = 0;
    for(int i =0;i<nums.size();i++)
    {
        sum = sum + nums[i];
    }
      return maxsum;  
        maxsum = max(maxsum,sum);
    int maxsum= INT_MIN;
        if(sum<0)
        {
            sum=0;
        }
    }
};
