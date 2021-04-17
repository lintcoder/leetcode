int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int i = 1;
        while (i < len)
        {
            if (nums[i] == nums[i-1])
                break;
            ++i;
        }
        
        return nums[i];
    }