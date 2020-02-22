int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ct = 0;
        for (int i = 0; i < row; ++i)
        {
            ct += lower_bound(grid[i].rbegin(), grid[i].rend(), 0) - grid[i].rbegin();
        }
        
        return ct;
    }