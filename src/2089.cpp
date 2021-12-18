vector<int> targetIndices(vector<int>& nums, int target) {
        int len = nums.size();
        int arr[101] = {0};
        for (int i = 0; i < len; ++i)
            arr[nums[i]]++;
        
        if (arr[target] == 0)
            return {};
        
        vector<int> res(arr[target], 0);
        int ct = 0;
        ct = accumulate(arr, arr+target, ct);
        for (int i = 0; i < arr[target]; ++i)
            res[i] = ct+i;
        
        return res;
    }