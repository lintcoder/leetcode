int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> res(n*(n+1)/2, 0);
        int k = -1;
        for (int i = 0; i < n; ++i)
        {
            res[++k] = nums[i];
            for (int j = i+1; j < n; ++j)
            {
                int tmp = res[k] + nums[j];
                res[++k] = tmp;
            }
        }
        
        sort(res.begin(), res.end());
        long long sum = 0;
        for (int i = left-1; i < right; ++i)
            sum += res[i];
        
        return sum%(1000000000+7);
    }