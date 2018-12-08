int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return len-1;
        if (len == 2)
        {
            if (nums[1] == 0)
                return 0;
            else if (nums[0] == 0)
                return 1;
            else
                return -1;
        }

        vector<int> subsum(len, 0);
        int sum = 0;
        for (int i = 0; i < len; ++i)
        {
            sum += nums[i];
            subsum[i] = sum;
        }
        
        if (sum-nums[0] == 0)
            return 0;
        for (int i = 0; i < len-1; ++i)
        {
            if (subsum[i] == sum-subsum[i+1])
            return i+1;
        }

        return -1;
    }