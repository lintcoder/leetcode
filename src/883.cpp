int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;
        for (int i = 0; i < n; ++i)
        {
            int maxvalrow = 0;
            int maxvalcol = 0;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] > 0)
                    area++;
                if (grid[i][j] > maxvalrow)
                    maxvalrow = grid[i][j];
                if (grid[j][i] > maxvalcol)
                    maxvalcol = grid[j][i];
            }
            
            area += maxvalrow + maxvalcol;
        }
        
        return area;
    }