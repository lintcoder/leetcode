int findMaxK(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0, j = len-1;
        while (i < j)
        {
            if (nums[i] == -nums[j])
                return nums[j];
            else if (-nums[i] < nums[j])
                --j;
            else
                ++i;
        }
        
        return -1;
    }