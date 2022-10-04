int maxSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int maxsum = 0, sum = 0;
        
        for (int r = 0; r < row-2; ++r)
        {
            for (int c = 0; c < col-2; ++c)
            {
                sum = grid[r][c]+grid[r][c+1]+grid[r][c+2]+grid[r+1][c+1]+
                    grid[r+2][c]+grid[r+2][c+1]+grid[r+2][c+2];
                if (sum > maxsum)
                    maxsum = sum;
            }
        }
        
        return maxsum;
    }