vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        if (row == 1 || col == 1)
            return mat;
        
        int minval = row < col ? row : col;
        vector<int> vec(minval);
        for (int i = row-2; i >= 0; --i)
        {
            int k = row-i;
            if (col < k)
                k = col;
            for (int j = 0; j < k; ++j)
                vec[j] = mat[i+j][j];
            sort(vec.begin(), vec.begin()+k);
            for (int j = 0; j < k; ++j)
                mat[i+j][j] = vec[j];
        }
        
        for (int i = 1; i < col-1; ++i)
        {
            int k = col-i;
            if (row < k)
                k = row;
            for (int j = 0; j < k; ++j)
                vec[j] = mat[j][i+j];
            sort(vec.begin(), vec.begin()+k);
            for (int j = 0; j < k; ++j)
                mat[j][i+j] = vec[j];
        }
        
        return mat;
    }