int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int len = dominoes.size();
        if (len == 1)
            return 0;
        vector<vector<int>> vec(9, vector<int>(9, 0));
        for (int i = 0; i < len; ++i)
        {
            int r = dominoes[i][0];
            int c = dominoes[i][1];
            if (r > c)
            {
                int t = r;
                r = c;
                c = t;
            }
            vec[r-1][c-1]++;
        }
        
        int res = 0;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = i; j < 9; ++j)
                if (vec[i][j] != 0)
                    res += vec[i][j]*(vec[i][j]-1)/2;
        }
        
        return res;
    }