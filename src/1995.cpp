int countQuadruplets(vector<int>& nums) {
        int len = nums.size();
        int ct = 0;
        
        for (int i = 0; i < len-3; ++i)
        {
            for (int j = i+1; j < len-2; ++j)
            {
                for (int m = j+1; m < len-1; ++m)
                {
                    for (int n = m+1; n < len; ++n)
                        if (nums[i]+nums[j]+nums[m] == nums[n])
                            ++ct;
                }
            }
        }
        
        return ct;
    }