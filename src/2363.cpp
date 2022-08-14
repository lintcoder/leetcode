vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int len1 = items1.size();
        int len2 = items2.size();
        
        map<int, int> mp;
        for (int i = 0; i < len1; ++i)
            mp[items1[i][0]] += items1[i][1];
        for (int i = 0; i < len2; ++i)
            mp[items2[i][0]] += items2[i][1];
        
        int sz = mp.size();
        int k = 0;
        vector<vector<int>> res(sz, vector<int>(2, 0));
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            res[k][0] = iter->first;
            res[k][1] = iter->second;
            ++k;
        }
        
        return res;
    }