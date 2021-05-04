int arraySign(vector<int>& nums) {
        int len = nums.size();
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] < 0)
                ++ct;
            else if (nums[i] == 0)
                return 0;
        }
        
        return ct%2 == 0 ? 1 : -1;
    }