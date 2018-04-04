vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        if (row == 0)
            return nums;
        int col = nums[0].size();
        if (row * col != r * c || (row == r && col == c))
            return nums;
        
        vector<vector<int> > res;
        vector<int> rownum(c, 0);
        int m = 0, n = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (n == col)
                {
                    m++;
                    n = 0;
                }
                rownum[j] = nums[m][n];
                n++;
            }
            res.push_back(rownum);
        }
        
        return res;
    }