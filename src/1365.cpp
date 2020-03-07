vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int len = nums.size();
        vector<int> ct(101);
        vector<int> sum(101);
        for (int i = 0; i < len; ++i)
            ++ct[nums[i]];
        
        int subsum = 0;
        for (int i = 1; i < 101; ++i)
        {
            subsum += ct[i-1];
            sum[i] = subsum;
        }
        
        vector<int> res(len);
        for (int i = 0; i < len; ++i)
            res[i] = sum[nums[i]];
        
        return res;
    }