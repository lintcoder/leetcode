vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row = grid.size();
        int n = row-2;
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        for (int i = 1; i < row-1; ++i)
        {
            for (int j = 1; j < row-1; ++j)
            {
                int maxvalue = 0;
                for (int p = i-1; p <= i+1; ++p)
                {
                    for (int q = j-1; q <= j+1; ++q)
                    {
                        if (grid[p][q] > maxvalue)
                            maxvalue = grid[p][q];
                    }
                }
                res[i-1][j-1] = maxvalue;
            }
        }
        
        return res;
    }