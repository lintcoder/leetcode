vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        long long total = 1;
        for (int i = len; i >= 1; --i)
            total *= i;
        vector<vector<int>> res(total, vector<int>(len, 0));
        res[0].assign(nums.begin(), nums.end());
        
        int i = 1;
        while (next_permutation(nums.begin(), nums.end()))
        {
            res[i++].assign(nums.begin(), nums.end());
        }
        
        return move(res);
    }