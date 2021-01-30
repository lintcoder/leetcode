int specialArray(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        int k = nums[len-1];
        mp[k] = 1;
        for (int i = len-2; i >= 0; --i)
        {
            if (nums[i] == k)
            {
                mp[k]++;
            }
            else
            {
                mp[nums[i]] = mp[k] + 1;
                k = nums[i];
            }
        }
        
        int n = mp.begin()->first;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->first == iter->second)
                return iter->first;
            else if (iter->first > iter->second)
            {
                if (iter == mp.begin() || iter->second > n)
                    return iter->second;
            }
            n = iter->first;
        }
        
        return -1;
    }