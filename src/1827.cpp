int minOperations(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] <= nums[i-1])
            {
                sum += nums[i-1]-nums[i]+1;
                nums[i] = nums[i-1]+1;
            }
        }
        
        return sum;
    }