int minStartValue(vector<int>& nums) {
        int len = nums.size();
        int minval = nums[0];
        int sum = minval;
        for (int i = 1; i < len; ++i)
        {
            sum += nums[i];
            if (sum < minval)
                minval = sum;
        }
        
        if (minval >= 0)
            return 1;
        else
            return abs(minval) + 1;
    }