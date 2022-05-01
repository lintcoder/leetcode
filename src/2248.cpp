vector<int> intersection(vector<vector<int>>& nums) {
        int len = nums.size();
        int arr[1001] = {0};
        for (int i = 0; i < len; ++i)
        {
            int sz = nums[i].size();
            for (int j = 0; j < sz; ++j)
                ++arr[nums[i][j]];
        }
        
        vector<int> res(1000, 0);
        int k = 0;
        for (int i = 0; i < 1001; ++i)
        {
            if (arr[i] == len)
                res[k++] = i;
        }
        
        
        return vector<int>(res.begin(), res.begin()+k);
    }