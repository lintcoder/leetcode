int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if (row == 1 && col == 1)
            return grid[0][0] == 1 ? -1 : 0;
        
        int ct = 0;
        vector<vector<int>> flag(row, vector<int>(col, 0));
        while (true)
        {
            bool flag2 = false;
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    if (flag[i][j] == 0 && grid[i][j] == 2)
                    {
                        flag2 |= search(grid, row, col, flag, i, j);
                    }
                }
            }
            if (!flag2)
                break;
            else
                ++ct;
            flag.assign(row, vector<int>(col, 0));
        }
        
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
                if (grid[i][j] == 1)
                    return -1;
        }
        
        return ct;
    }
    
    bool search(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& flag, int m, int n)
    {
        deque<pair<int,int>> dq;
        dq.push_back(make_pair(m, n));
        int len = 1;
        bool status = false;
        while (len != 0)
        {
            for (int i = 0; i < len; ++i)
            {
                int p = dq[i].first, q = dq[i].second;
                flag[p][q] = 1;
                grid[p][q] = 0;
                if (p > 0 && flag[p-1][q] == 0 && grid[p-1][q] != 0)
                {
                    if (grid[p-1][q] == 1)
                    {
                        grid[p-1][q] = 2;
                        status = true;
                    }
                    else
                    {
                        grid[p-1][q] = 0;
                        dq.push_back(make_pair(p-1, q));
                    }
                    flag[p-1][q] = 1;
                }
                if (p < row-1 && flag[p+1][q] == 0 && grid[p+1][q] != 0)
                {
                    if (grid[p+1][q] == 1)
                    {
                        grid[p+1][q] = 2;
                        status = true;
                    }
                    else
                    {
                        grid[p+1][q] = 0;
                        dq.push_back(make_pair(p+1, q));
                    }
                    flag[p+1][q] = 1;
                }
                if (q > 0 && flag[p][q-1] == 0 && grid[p][q-1] != 0)
                {
                    if (grid[p][q-1] == 1)
                    {
                        grid[p][q-1] = 2;
                        status = true;
                    }
                    else
                    {
                        grid[p][q-1] = 0;
                        dq.push_back(make_pair(p, q-1));
                    }
                    flag[p][q-1] = 1;
                }
                if (q < col-1 && flag[p][q+1] == 0 && grid[p][q+1] != 0)
                {
                    if (grid[p][q+1] == 1)
                    {
                        grid[p][q+1] = 2;
                        status = true;
                    }
                    else
                    {
                        grid[p][q+1] = 0;
                        dq.push_back(make_pair(p, q+1));
                    }
                    flag[p][q+1] = 1;
                }
            }
            dq.erase(dq.begin(), dq.begin()+len);
            len = dq.size();
        }
        
        return status;
    }