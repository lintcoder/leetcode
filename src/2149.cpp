vector<int> rearrangeArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        int even = 0, odd = 1;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] > 0)
            {
                res[even] = nums[i];
                even += 2;
            }
            else
            {
                res[odd] = nums[i];
                odd += 2;
            }
        }
        
        return res;
    }