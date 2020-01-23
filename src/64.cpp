int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();
        
        vector<vector<int>> sum(row, vector<int>(col, -1));
        return search(0, 0, row, col, grid, sum);
    }
    
    int search(int p, int q, int m, int n, const vector<vector<int>>& grid, vector<vector<int>>& sum)
    {
        if (sum[p][q] == -1)
        {
            if (p < m-1 && q < n-1)
            {
                int v1 = search(p+1, q, m, n, grid, sum);
                int v2 = search(p, q+1, m, n, grid, sum);
                sum[p][q] = v1 < v2 ? v1+grid[p][q] : v2+grid[p][q];
                return sum[p][q];
            }
            else if (p == m-1)
            {
                int t = 0;
                for (int i = q; i < n; ++i)
                    t += grid[p][i];
                sum[p][q] = t;
                return t;
            }
            else
            {
                int t = 0;
                for (int i = p; i < m; ++i)
                    t += grid[i][q];
                sum[p][q] = t;
                return t;
            }
        }
        else
            return sum[p][q];
    }