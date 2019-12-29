vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int len = groupSizes.size();
        vector<vector<int>> res;
        map<int, vector<int>> mp;
        for (int i = 0; i < len; ++i)
            mp[groupSizes[i]].push_back(i);
        
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            int sz = (iter->second).size();
            vector<int> tmp(iter->first, 0);
            for (int i = 0; i < sz; i += iter->first)
            {
                for (int j = i; j < i+iter->first; ++j)
                    tmp[j-i] = (iter->second)[j];
                res.push_back(tmp);
            }
        }
        
        return res;
    }