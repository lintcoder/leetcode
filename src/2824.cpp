int countPairs(vector<int>& nums, int target) {
        int len = nums.size();
        int ct = 0;
        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                if (nums[i]+nums[j] < target)
                    ++ct;
            }
        }

        return ct;
    }