vector<int> findLonely(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums;
        sort(nums.begin(), nums.end());
        
        vector<int> res;
        if (nums[1] > nums[0]+1)
            res.push_back(nums[0]);
        
        for (int i = 1; i < len-1; ++i)
        {
            if ((nums[i] > nums[i-1]+1) && (nums[i] < nums[i+1]-1))
                res.push_back(nums[i]);
        }
        if (nums[len-1] > nums[len-2]+1)
            res.push_back(nums[len-1]);
        
        return res;
    }