vector<int> applyOperations(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        while (i < len-1)
        {
            if (nums[i] == nums[i+1])
            {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
            ++i;
        }
        
        i = 0;
        vector<int> res(len, 0);
        for (int j = 0; j < len; ++j)
        {
            if(nums[j] != 0)
                res[i++] = nums[j];
        }
        
        return res;
    }