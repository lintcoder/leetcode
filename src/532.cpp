int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (len <= 1)
            return 0;
        if (len == 2)
            return nums[1]-nums[0] == k ? 1 : 0;
        int i = 0;
        int j = 1;
        int ct = 0;
        while (i < len-1 && j < len)
        {
            int t = nums[j] - nums[i];
            if (t < k)
                ++j;
            else
            {
                if (t == k)
                    ++ct;
                int n = i+1;
                while (n < len && nums[n] == nums[i])
                    ++n;
                i = n;
                j = i+1;
            }
        }
        
        return ct;
    }