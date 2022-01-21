int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> vec(m, vector<int>(n, 0));
        int len = indices.size();
        for (int i = 0; i < len; ++i)
        {
            int row = indices[i][0], col = indices[i][1];
            for (int r = 0; r < m; ++r)
                vec[r][col]++;
            for (int c = 0; c < n; ++c)
                vec[row][c]++;
        }
        
        int ct = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (vec[i][j]%2 == 1)
                    ++ct;
            }
        }
        
        return ct;
    }