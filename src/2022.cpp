vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        if (m*n != len)
            return {};
        
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res[i][j] = original[i*n + j];
            }
        }
        
        return res;
    }