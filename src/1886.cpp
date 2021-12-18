bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row = mat.size();
        bool flag = true;
        
        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < row; ++c)
            {
                if (mat[r][c] != target[r][c])
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if (!flag)
        {
            flag = true;
            for (int r = 0; r < row; ++r)
            {
                for (int c = 0; c < row; ++c)
                {
                    if (mat[r][c] != target[row-1-r][row-1-c])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        if (!flag)
        {
            flag = true;
            for (int r = 0; r < row; ++r)
            {
                for (int c = 0; c < row; ++c)
                {
                    if (mat[r][c] != target[row-1-c][r])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        if (!flag)
        {
            flag = true;
            for (int r = 0; r < row; ++r)
            {
                for (int c = 0; c < row; ++c)
                {
                    if (mat[r][c] != target[c][row-1-r])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        return flag;
    }