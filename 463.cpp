int islandPerimeter(vector<vector<int>>& grid) {
    int row = grid.size();
    if (row == 0)
        return 0;
    int col = grid[0].size();

    int sum = 0, cnt = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (grid[i][j] == 1)
            {
                ++sum;
                if (j == 0 && i != row - 1)
                    cnt += grid[i][j] == 1 && grid[i + 1][j] == 1;
                else if (j != 0 && i == row - 1)
                    cnt += grid[i][j] == 1 && grid[i][j - 1] == 1;
                else if (j != 0 && i != row - 1)
                    cnt += (grid[i][j] == 1 && grid[i][j - 1] == 1) + (grid[i][j] == 1 && grid[i + 1][j]);
            }
        }
    }

    return sum * 4 - cnt * 2;
}
