vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int len = creators.size();
        map<string, tuple<long long, int, string>> mp;
        
        long long maxview = 0;
        for (int i = 0; i < len; ++i)
        {
            if (views[i] > get<1>(mp[creators[i]]))
            {
                get<1>(mp[creators[i]]) = views[i];
                get<2>(mp[creators[i]]) = ids[i];
            }
            else if (views[i] == get<1>(mp[creators[i]]))
            {
                if (get<2>(mp[creators[i]]) == "")
                    get<2>(mp[creators[i]]) = ids[i];
                else if (ids[i] < get<2>(mp[creators[i]]))
                    get<2>(mp[creators[i]]) = ids[i];
                
            }
            get<0>(mp[creators[i]]) += views[i];
            if (get<0>(mp[creators[i]]) > maxview)
                maxview = get<0>(mp[creators[i]]);
        }
        
        vector<vector<string>> res;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if (get<0>(iter->second) == maxview)
            {
                res.push_back({iter->first, get<2>(iter->second)});
            }
        }
        
        return res;
    }