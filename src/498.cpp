vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        vector<int> res;
        int row = matrix.size();
        if (row == 0)
                return res;
        if (row == 1)
                return matrix[0];
        int col = matrix[0].size();
        if (col == 1)
        {
            for (int i = 0; i < row; ++i)
                res.push_back(matrix[i][0]);
            return res;
        }

        int i = 0, j = 0;
        bool down = false;
        while (i < row && j < col)
        {
            res.push_back(matrix[i][j]);
            if (i == row - 1 && j == col - 1)
                break;
            if (i == 0)
            {
                if (!down)
                {
                    if (j < col - 1)
                        ++j;
                    else
                        ++i;
                    down = !down;
                }
                else
                {
                    ++i;
                    --j;
                }
            }
            else
            {
                if (down)
                {
                    if (j == 0)
                    {
                        if (i < row - 1)
                            ++i;
                        else
                            ++j;
                        down = !down;
                    }
                    else
                    {
                        if (i < row - 1)
                        {
                            ++i;
                            --j;
                        }
                        else
                        {
                            ++j;
                            down = !down;
                        }
                    }
                }
                else
                {
                    if (j < col - 1)
                    {
                        --i;
                        ++j;
                    }
                    else
                    {
                        ++i;
                        down = !down;
                    }
                }
            }
        }

        return res;
    }