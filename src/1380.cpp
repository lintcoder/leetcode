vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int> res;
        for (int i = 0; i < row; ++i)
        {
            int minval = matrix[i][0];
            int index = 0;
            int j = 0;
            for (j = 1; j < col; ++j)
            {
                if (matrix[i][j] < minval)
                {
                    index = j;
                    minval = matrix[i][j];
                }
            }
            
            bool flag = true;
            for (j = 0; j < row; ++j)
            {
                if (matrix[j][index] > minval)
                {
                    flag = false;
                    break;
                }
            }
            
            if (flag)
                res.push_back(minval);
        }
        
        return res;
    }