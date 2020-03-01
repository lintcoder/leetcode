vector<vector<int>> largeGroupPositions(string S) {
        int len = S.size();
        if (len <= 2)
            return {};
        
        int ct = 1;
        int c = S[0];
        int i = 1;
        int p = 0, q = 0;
        vector<vector<int>> res;
        while (i < len)
        {
            if (S[i] == c)
            {
                ++ct;
                q = i;
            }   
            else
            {
                if (ct >= 3)
                {
                    res.push_back({p, q});
                }
                p = i;
                q = i;
                c = S[i];
                ct = 1;
            }
            ++i;
        }
        if (ct >= 3)
            res.push_back({p, q});
        
        return res;
    }