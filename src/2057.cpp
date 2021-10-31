int smallestEqual(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            if (i%10 == nums[i])
                return i;
        }
        
        return -1;
    }