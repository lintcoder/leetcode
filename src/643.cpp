double findMaxAverage(vector<int>& nums, int k) {
        int maxsum = INT_MIN;
        int len = nums.size();
        if (len <= k-1)
            return 0;
        int subsum = 0;
        for (int i = 0; i < k; ++i)
            subsum += nums[i];
        if (subsum > maxsum)
            maxsum = subsum;
        int i = 0, j = k;
        while (j < len)
        {
            subsum = subsum - nums[i] + nums[j];
            if (subsum > maxsum)
                maxsum = subsum;
            ++i;
            ++j;
        }
        
        return (double)maxsum/k;
    }