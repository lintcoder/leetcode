int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        map<pair<int,int>,int> mp;
        int len = artifacts.size();
        for (int i = 0; i < len; ++i)
        {
            int r1 = artifacts[i][0], c1 = artifacts[i][1];
            int r2 = artifacts[i][2], c2 = artifacts[i][3];
            for (int j = r1; j <= r2; ++j)
            {
                for (int k = c1; k <= c2; ++k)
                    mp[make_pair(j,k)] = i+1;
            }
        }
        
        int sz = dig.size();
        for (int i = 0; i < sz; ++i)
            mp[make_pair(dig[i][0], dig[i][1])] = 0;
        
        set<int> st;
        auto iterLast = mp.end();
        for (auto iter = mp.begin(); iter != iterLast; ++iter)
        {
            if (iter->second != 0)
                st.insert(iter->second);
        }
        
        return len - st.size();
    }