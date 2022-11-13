int averageValue(vector<int>& nums) {
        int len = nums.size();
        int ct = 0, sum = 0;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i]%6 == 0)
            {
                sum += nums[i];
                ++ct;
            }
        }
        
        if (ct != 0)
            return sum/ct;
        else
            return 0;
    }