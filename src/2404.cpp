int mostFrequentEven(vector<int>& nums) {
        int len = nums.size();
        map<int, int> mp;
        
        for (int i = 0; i < len; ++i)
        {
            if (nums[i]%2 == 0)
                mp[nums[i]]++;
        }
        
        int maxnum = 0, val = 0;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (iter->second > maxnum)
            {
                maxnum = iter->second;
                val = iter->first;
            }
            else if (iter->second == maxnum && iter->first < val)
            {
                val = iter->first;
            }
        }
        
        if (maxnum == 0)
            return -1;
        else
            return val;
    }