vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        int lhs_len = findNums.size();
        int rhs_len = nums.size();
        
        map<int, int> mp;
        for (int i = 0; i < rhs_len; ++i)
            mp[nums[i]] = i;
        for (int i = 0; i < lhs_len; ++i)
        {
            int pos = mp[findNums[i]];
            if (pos == rhs_len - 1)
                res.push_back(-1);
            else
            {
                int j = 0;
                for (j = pos + 1; j < rhs_len; ++j)
                    if (nums[j] > findNums[i])
                    {
                        res.push_back(nums[j]);
                        break;
                    }
                if (j == rhs_len)
                    res.push_back(-1);
            }
        }
        
        return res;
    }