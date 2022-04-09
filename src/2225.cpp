vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int,int>> mp;
        int len = matches.size();
        for (int i = 0; i < len; ++i)
        {
            mp[matches[i][0]].first++;
            mp[matches[i][1]].second++;
        }
        
        vector<vector<int>> res(2, vector<int>{});
        auto iterLast = mp.end();
        for (auto iter = mp.begin(); iter != iterLast; ++iter)
        {
            if (iter->second.second == 0)
                res[0].push_back(iter->first);
            if (iter->second.second == 1)
                res[1].push_back(iter->first);
        }
        
        return res;
    }