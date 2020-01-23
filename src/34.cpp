vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (!binary_search(nums.begin(), nums.end(), target))
            return res;
        
        auto iter = lower_bound(nums.begin(), nums.end(), target);
        res[0] = iter-nums.begin();
        iter = upper_bound(nums.begin(), nums.end(), target);
        res[1] = iter-1-nums.begin();
        
        return res;
    }