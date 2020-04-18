vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int len = nums.size();
        vector<int> res(len, -1);
        for (int i = 0; i < len; ++i)
        {
            if (res[index[i]] == -1)
                res[index[i]] = nums[i];
            else
                res.insert(res.begin()+index[i], 1, nums[i]);
        }
        
        res.resize(len);
        return res;
    }