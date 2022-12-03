int unequalTriplets(vector<int>& nums) {
        int len = nums.size();
        int ct = 0;
        
        for (int i = 0; i < len-2; ++i)
        {
            for (int j = i+1; j < len-1; ++j)
            {
                for (int k = j+1; k < len; ++k)
                {
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k])
                        ++ct;
                }
            }
        }
        
        return ct;
    }