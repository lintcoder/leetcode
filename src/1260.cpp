vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int sz = row*col;
        k %= sz;
        if (k == 0)
            return grid;
        vector<vector<int>> res(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                int t = (i*col+j+k)%sz;
                int r = t/col, c = t%col;
                res[r][c] = grid[i][j];
            }
        }
        
        return res;
    }