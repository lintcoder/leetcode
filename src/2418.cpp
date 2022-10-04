vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int len = names.size();
        vector<string> res(len, "");
        
        map<int, string> mp;
        for (int i = 0; i < len; ++i)
        {
            mp[heights[i]] = names[i];
        }
        
        int k = 0;
        for (auto iter = mp.rbegin(); iter != mp.rend(); ++iter)
            res[k++] = iter->second;
        
        return res;
    }