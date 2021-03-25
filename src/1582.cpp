int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        map<int, int> rowmp, colmp;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (mat[i][j] == 1)
                {
                    rowmp[i]++;
                    colmp[j]++;
                }
            }
        }

        int ct = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (mat[i][j] == 1 && rowmp[i] == 1 && colmp[j] == 1)
                    ++ct;
            }
        }
        
        return ct;
    }