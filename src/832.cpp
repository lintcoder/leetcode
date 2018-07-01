vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row = A.size();
        if (row == 0)
            return A;
        int col = A[0].size();
        for (int i = 0; i < row; ++i)
        {
            int lim = col/2;
            for (int j = 0; j < lim; ++j)
            {
                if (A[i][j] == A[i][col-1-j])
                {
                    A[i][j] = 1 - A[i][j];
                    A[i][col-1-j] = 1 - A[i][col-1-j];
                }
            }
            if (col%2 != 0)
                A[i][lim] = 1 - A[i][lim];
        }
        
        return A;
    }