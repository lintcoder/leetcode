int countPairs(vector<int>& nums, int k) {
        int ct = 0;
        int len = nums.size();
        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                if (nums[i] == nums[j] && (i*j%k == 0))
                    ++ct;
            }
        }
        
        return ct;
    }