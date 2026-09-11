        for(int i =0;i<nums.size();i++)
        {
            hash[nums[i]]++;
        }
        for(int i =0;i<=100;i++)
        {
            if(hash[i]==1)
            {
              sum = sum +i;
            }
        }
        return sum;
    }
};
