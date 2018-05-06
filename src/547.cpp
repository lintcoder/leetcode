int findCircleNum(vector<vector<int>>& M) {
        int num = M.size();
        int count = 0;
        for (int i = 0; i < num; ++i)
        {
            if (M[i][i] == 1)
            {
                M[i][i] = -1;
                for (int j = 0; j < num; ++j)
                {
                    if (j != i && M[i][j] == 1)
                    {
                        M[i][j] = M[j][i] = -1;
                        doSubFind(M, j, num);
                    }
                }
                count++;
            }
        }

        return count;
    }

    void doSubFind(vector<vector<int>>& M, int row, const int num)
    {
        if (M[row][row] == 1)
        {
            M[row][row] = -1;
            for (int i = 0; i < num; ++i)
            {
                if (i != row && M[row][i] == 1)
                {
                    M[row][i] = M[i][row] = -1;
                    doSubFind(M, i, num);
                }
            }
        }
    }