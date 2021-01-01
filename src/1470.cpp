vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(n*2);
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            res[j] = nums[i];
            res[j+1] = nums[i+n];
            j += 2;
        }
        
        return res;
    }