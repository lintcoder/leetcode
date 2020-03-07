vector<int> powerfulIntegers(int x, int y, int bound) {
        if (bound <= 1)
            return {};
        if (bound == 2)
            return {2};
        if (x == 1 && y == 1)
            return {2};
        if (x == 1 || y == 1)
        {
            int t = x != 1 ? x : y;
            int x = 1;
            int sz = log(bound-1)/log(t)+1;
            vector<int> res(sz);
            for (int i = 0; i < sz; ++i)
            {
                res[i] = 1+x;
                x *= t;
            }
            return res;
        }
        
        int m = log(bound)/log(x);
        int n = log(bound)/log(y);
        set<int> st;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                double t = pow(x, i) + pow(y, j);
                if (t <= bound)
                    st.insert(t);
            }
        }
        
        vector<int> res;
        res.assign(st.begin(), st.end());
        return res;
    }