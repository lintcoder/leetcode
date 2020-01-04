int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        
        int i = 1;
        int maxsum = nums[0];
        int tmp = maxsum;
        while (i < len)
        {
            if (tmp <= 0)
            {
                if (nums[i] >= tmp)
                {
                    tmp = nums[i];
                    if (tmp > maxsum)
                        maxsum = tmp;
                }    
                ++i;
            }
            else
            {
                tmp += nums[i];
                if (tmp > maxsum)
                    maxsum = tmp;
                ++i;
            }
        }
        
        if (tmp > maxsum)
            maxsum = tmp;
        
        return maxsum;
    }