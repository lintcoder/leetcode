int numOfPairs(vector<string>& nums, string target) {
        int len = nums.size();
        int targetlen = target.size();
        vector<int> sz_vec(len, 0);
        for (int i = 0; i < len; ++i)
            sz_vec[i] = nums[i].size();
        
        int ct = 0;
        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                if (sz_vec[i] + sz_vec[j] == targetlen)
                {
                    if (nums[i] + nums[j] == target)
                        ct += 1;
                    if (nums[j] + nums[i] == target)
                        ct += 1;
                }
            }
        }
        
        return ct;
    }