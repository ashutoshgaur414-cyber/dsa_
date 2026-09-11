public:
    vector<int> buildArray(vector<int>& nums) {
        for(int i =0;i<n;i++)
        {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
        vector<int>ans(n);
        int n = nums.size();
};
