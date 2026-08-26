class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
     
   int candidate = k;

   while(true)
   {
    bool found = false;
     for(int i = 0;i<nums.size();i++)
     {
        if(candidate==nums[i])
        {
            found = true;
        }
     }
     if(!found)
     {
        return candidate;
     }
     candidate = candidate +k;
   }

    }
};