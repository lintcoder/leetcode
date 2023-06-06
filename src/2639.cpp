vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<int> res(col, 0);
        for (int i = 0; i < col; ++i)
        {
            int maxlen = 0;
            for (int j = 0; j < row; ++j)
            {
                int n = 1;
                if (grid[j][i] != 0)
                {
                    n = log10(abs(grid[j][i]))+1;
                    if (grid[j][i] < 0)
                        ++n;
                }
                if (n > maxlen)
                    maxlen = n;
            }

            res[i] = maxlen;
        }

        return res;
    }