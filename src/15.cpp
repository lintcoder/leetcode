vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3)
            return res;
        
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        while (i < len-2)
        {
            if (nums[i] > 0)
                break;
            j = i+1;
            while (j < len-1)
            {
                if (nums[i]+nums[j] > 0)
                {
                    break;
                }
                bool ans = binary_search(nums.begin()+j+1, nums.end(), -nums[i]-nums[j]);
                if (ans)
                    res.push_back({nums[i], nums[j], -nums[i]-nums[j]});
                auto iter = upper_bound(nums.begin()+j+1, nums.end(), nums[j]);
                if (iter == nums.end())
                    break;
                j = iter-nums.begin();
            }
            
            auto iter2 = upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
            if (iter2 == nums.end())
                break;
            else
                i = iter2-nums.begin();
        }
        
        return res;
    }