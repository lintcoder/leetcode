int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return 0;
        
        vector<int> vec(nums);
        sort(vec.begin(), vec.end());
        int i = 0;
        for (i = 0; i < len; ++i)
            if (nums[i] != vec[i])
                break;
        if (i == len)
            return 0;
        int j = len-1;
        for (j = len-1; j >= 0; --j)
            if (nums[j] != vec[j])
                break;
        return j-i+1;
    }
