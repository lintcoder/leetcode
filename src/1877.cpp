int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        int maxval = 0;
        int n = len/2;
        for (int i = 0; i < n; ++i)
        {
            int val = nums[i]+nums[len-1-i];
            if (val > maxval)
                maxval = val;
        }
        
        return maxval;
    }