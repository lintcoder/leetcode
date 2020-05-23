string destCity(vector<vector<string>>& paths) {
        map<string, int> mp;
        int len = paths.size();
        for (int i = 0; i < len; ++i)
        {
            if (mp.find(paths[i][0]) == mp.end())
                mp[paths[i][0]] = -1;
            else
                mp[paths[i][0]] = 0;
            if (mp.find(paths[i][1]) == mp.end())
                mp[paths[i][1]] = 1;
            else
                mp[paths[i][1]] = 0;
        }
        
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
            if (iter->second == 1)
                return iter->first;
        
        return "";
    }