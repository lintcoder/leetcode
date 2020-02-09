bool isPossibleDivide(vector<int>& nums, int k) {
        int len = nums.size();
        if (len%k != 0)
            return false;
        
        map<int, int> mp;
        for (int i = 0; i < len; ++i)
            mp[nums[i]]++;
        
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second == 0)
                continue;
            int t = iter->first;
            for (int i = t+1; i < t+k; ++i)
            {
                if (mp[i] < iter->second)
                    return false;
                else
                    mp[i] -= iter->second;
            }
        }
        
        return true;
    }