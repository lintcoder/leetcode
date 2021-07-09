vector<int> buildArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        for (int i = 0; i < len; ++i)
        {
            res[i] = nums[nums[i]];
        }
        
        return res;
    }