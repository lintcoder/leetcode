int tupleSameProduct(vector<int>& nums) {
        int len = nums.size();
        map<int, int> mp;
        for (int i = 0; i < len; ++i)
        {
            for (int j = i+1; j < len; ++j)
                mp[nums[i]*nums[j]]++;
        }
        
        int sum = 0;
        auto iterend = mp.end();
        for (auto iter = mp.begin(); iter != iterend; ++iter)
        {
            if (iter->second > 1)
                sum += iter->second*(iter->second-1)*4;
        }
        
        return sum;
    }