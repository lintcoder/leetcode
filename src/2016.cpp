    int maximumDifference(vector<int>& nums) {
        int len = nums.size();
        int maxdiff = 0;
        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                int diff = nums[j]-nums[i];
                if (diff > maxdiff)
                    maxdiff = diff;
            }
        }
        
        if (maxdiff == 0)
            maxdiff = -1;
        
        return maxdiff;
    }