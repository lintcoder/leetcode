int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        if (row == 1 && col == 1)
        {
            return obstacleGrid[0][0] == 0 ? 1 : 0;
        }

        vector<vector<int>> dp(row, vector<int>(col, 0));
        int r = 0, c = 0;
        while (r < row)
        {
            if (obstacleGrid[r][0] == 0)
            {
                dp[r][0] = 1;
                ++r;
            }    
            else
            {
                while (r < row)
                {
                    dp[r][0] = -1;
                    ++r;
                }
            }
        }

        while (c < col)
        {
            if (obstacleGrid[0][c] == 0)
            {
                dp[0][c] = 1;
                ++c;
            }    
            else
            {
                while (c < col)
                {
                    dp[0][c] = -1;
                    ++c;
                }
            }
        }

        r = 1;
        while (r < row)
        {
            c = 1;
            while (c < col)
            {
                if (obstacleGrid[r][c] == 0)
                {
                    if (dp[r-1][c] == -1 && dp[r][c-1] == -1)
                        dp[r][c] = -1;
                    else
                    {
                        if (dp[r-1][c] != -1)
                            dp[r][c] += dp[r-1][c];
                        if (dp[r][c-1] != -1)
                            dp[r][c] += dp[r][c-1];
                    }
                }
                else
                    dp[r][c] = -1;
                ++c;
            }
            ++r;
        }
        
        return dp[row-1][col-1] > 0 ? dp[row-1][col-1] : 0;
    }