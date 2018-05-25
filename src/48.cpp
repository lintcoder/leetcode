void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row <= 1)
        	return;

        for (int i = 0; i < row/2; ++i)
        {
        	for (int j = i; j < row-1-i; ++j)
        	{
        		int tmp = matrix[row-1-i-(j-i)][i];
        		matrix[row-1-i-(j-i)][i] = matrix[row-1-i][row-1-i-(j-i)];
        		matrix[row-1-i][row-1-i-(j-i)] = matrix[j][row-1-i];
        		matrix[j][row-1-i] = matrix[i][j];
        		matrix[i][j] = tmp;
        	}
        }
    }