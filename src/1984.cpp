int minimumDifference(vector<int>& nums, int k) {
        if (k == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int mindiff = 1e5;
        
        for (int i = len-1; i >= k-1; --i)
        {
            int diff = nums[i]-nums[i-k+1];
            if (diff < mindiff)
                mindiff = diff;
        }
        
        return mindiff;
    }