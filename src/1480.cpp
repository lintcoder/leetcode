vector<int> runningSum(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        int sum = 0;
        for (int i = 0; i < len; ++i)
        {
            sum += nums[i];
            res[i] = sum;
        }
        
        return res;
    }