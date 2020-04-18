vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> res(row, vector<int>(col, 0));
        
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                for (int m = i-K; m <= i+K; ++m)
                {
                    for (int n = j-K; n <= j+K; ++n)
                    {
                        if (m >= 0 && m < row && n >= 0 && n < col)
                            res[i][j] += mat[m][n];
                    }
                }
            }
        }
        
        return res;
    }