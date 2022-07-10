int minMaxGame(vector<int>& nums) {
        int len = nums.size();
        while (len != 1)
        {
            int n = len/2;
            for (int i = 0; i < n; ++i)
            {
                if (i%2 == 0)
                    nums[i] = min(nums[i*2], nums[i*2+1]);
                else
                    nums[i] = max(nums[i*2], nums[i*2+1]);
            }
            len /= 2;
        }
        
        return nums[0];
    }