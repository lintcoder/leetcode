int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = ops.size();
        if (row == 0)
        	return m*n;
        int col = ops[0].size();

        int minrow = ops[0][0], mincol = ops[0][1];
        for (int i = 1; i < row; ++i)
        {
            if (ops[i][0] < minrow)
                minrow = ops[i][0];
            if (ops[i][1] < mincol)
                mincol = ops[i][1];
        }

        return minrow * mincol;
    }