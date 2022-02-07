int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int i = 0;
        while (i < len)
        {
            if (nums[i] == original)
                original *= 2;
            ++i;
        }
        
        return original;
    }