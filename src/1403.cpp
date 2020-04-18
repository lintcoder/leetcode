vector<int> minSubsequence(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return move(nums);
        
        int sum = 0;
        for (int i = 0; i < len; ++i)
            sum += nums[i];
        
        sort(nums.begin(), nums.end());
        vector<int> res;
        int subsum = 0;
        int i = len-1;
        for (i = len-1; i >= 0; --i)
        {
            subsum += nums[i];
            if (subsum > sum-subsum)
                break;
        }
        
        res.assign(nums.rbegin(), nums.rbegin()+len-i);
        
        return res;
    }