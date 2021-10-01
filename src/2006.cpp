int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        int len = nums.size();
        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                if (abs(nums[i]-nums[j]) == k)
                    ++res;
            }
        }
        
        return res;
    }