int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i)
            sort(grid[i].begin(), grid[i].end());
        
        int sum = 0;
        for (int i = n-1; i >= 0; --i)
        {
            int maxval = 0;
            for (int j = 0; j < m; ++j)
            {
                if (grid[j][i] > maxval)
                    maxval = grid[j][i];
            }

            sum += maxval;
        }

        return sum;
    }