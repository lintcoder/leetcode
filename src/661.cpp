vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size();
        if (row == 0)
        	return M;
        int col = M[0].size();

        vector<vector<int>> res(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i)
        {
        	for (int j = 0; j < col; ++j)
        	{
        		int sum = M[i][j];
                int ct = 1;
        		if (i > 0 && j > 0)
                {
                    sum += M[i-1][j-1];
                    ct++;
                }
        		if (i > 0)
                {
                    sum += M[i-1][j];
                    ct++;
                }
        		if (i > 0 && j < col-1)
                {	
                    sum += M[i-1][j+1];
                    ct++;
                }
        		if (j > 0)
                {
                    sum += M[i][j-1];
                    ct++;
                }
        		if (j < col-1)
                {
                    sum += M[i][j+1];
                    ct++;
                }
        		if (i < row-1 && j > 0)
                {
                    sum += M[i+1][j-1];
                    ct++;
                }
        		if (i < row-1)
                {
                    sum += M[i+1][j];
                    ct++;
                }
        		if (i < row-1 && j < col-1)
                {
                    sum += M[i+1][j+1];
                    ct++;
                }
        		res[i][j] = sum/ct;
        	}
        }

        return res;
    }