int findNumbers(vector<int>& nums) {
        int len = nums.size();
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            int t = 0;
            while (nums[i] != 0)
            {
                nums[i] /= 10;
                ++t;
            }
            if (t%2 == 0)
                ++ct;
        }
        
        return ct;
    }