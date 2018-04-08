bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return false;
        int col = matrix[0].size();
        if (row == 1 || col == 1)
            return true;
        
        for (int i = row - 2; i >= 0; --i)
        {
            for (int j = i+1, k = 1; j < row && k < col; ++j, ++k)
            {
                if (matrix[j][k] != matrix[i][0])
                    return false;
            }
        }
        
        for (int i = 1; i < col; ++i)
        {
            for (int j = 1, k = i+1; j < row && k < col; ++j, ++k)
            {
                if (matrix[j][k] != matrix[0][i])
                    return false;
            }
        }
        
        return true;
    }