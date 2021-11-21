vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return {};
        vector<string> res;
        
        int i = 0, j = 0;
        while (j < len-1)
        {
            if (nums[j] == nums[j+1]-1)
                ++j;
            else
            {
                if (i == j)
                    res.push_back(to_string(nums[i]));
                else
                    res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                i = j+1;
                j = i;
            }
        }
        
        if (i == j)
            res.push_back(to_string(nums[i]));
        else
            res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
        
        return res;
    }