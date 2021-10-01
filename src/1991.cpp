int findMiddleIndex(vector<int>& nums) {
        int len = nums.size();
        vector<int> subsum(len+1, 0);
        int sum = 0;
        subsum[0] = 0;
        for (int i = 1; i < len+1; ++i)
        {
            sum += nums[i-1];
            subsum[i] = sum;
        }
        
        int tmp = subsum[len];
        for (int i = 0; i < len; ++i)
        {
            if (subsum[i] == tmp-nums[i])
                return i;
            tmp -= nums[i];
        }
        
        return -1;
    }