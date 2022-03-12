vector<string> cellsInRange(string s) {
        int m = s[4]-s[1]+1;
        int n = s[3]-s[0]+1;
        int sum = m*n;
        
        vector<string> res(sum, "  ");
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                res[k][0] = s[0]+i;
                res[k][1] = s[1]+j;
                ++k;
            }
        }
        
        return res;
    }