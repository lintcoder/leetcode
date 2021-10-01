vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        int len = orders.size();
        map<int, map<string,int>> mp;
        set<string> st;
        
        for (int i = 0; i < len; ++i)
        {
            mp[atoi(orders[i][1].c_str())][orders[i][2]]++;
            st.insert(orders[i][2]);
        }
        
        int reslen = mp.size()+1;
        int foodnum = st.size();
        vector<vector<string>> res(reslen, vector<string>(foodnum+1, "0"));
        res[0][0] = "Table";
        
        int i = 1;
        for (auto iter = st.begin(); iter != st.end(); ++iter)
        {
            res[0][i++] = *iter;
        }
        
        i = 1;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            res[i][0] = to_string(iter->first);
            int j = 1;
            for (auto iterJ = st.begin(); iterJ != st.end(); ++iterJ)
            {
                if ((iter->second).find(*iterJ) == iter->second.end())
                    res[i][j++] = "0";
                else
                    res[i][j++] = to_string((iter->second)[*iterJ]);
            }    
            ++i;
        }
        
        return res;
    }