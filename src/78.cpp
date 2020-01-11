vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        int len = nums.size();
        if (len == 0)
            return res;
        
        vector<int> vec;
        search(nums, 0, len, vec, res);
        
        return move(res);
    }
    
    void search(vector<int>& nums, int index, int len, vector<int>& vec, vector<vector<int>>& res)
    {
        for (int i = index; i < len; ++i)
        {
            vector<int> tmp(vec);
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            search(nums, i+1, len, tmp, res);
        }
    }