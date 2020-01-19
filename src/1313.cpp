vector<int> decompressRLElist(vector<int>& nums) {
        int len = nums.size();
        int total = 0;
        for (int i = 0; i < len; i += 2)
            total += nums[i];
        vector<int> res(total, 0);
        int k = 0;
        for (int i = 0; i < len; i += 2)
        {
            int lim = k+nums[i];
            for (; k < lim; ++k)
                res[k] = nums[i+1];
        }
        
        return res;
    }
