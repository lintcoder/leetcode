vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> res(2, 0);
        for (int r = 0; r < row; ++r)
        {
            int ct = 0;
            for (int c = 0; c < col; ++c)
            {
                if (mat[r][c] == 1)
                    ++ct;
            }
            if (ct > res[1])
            {
                res[0] = r;
                res[1] = ct;
            }
        }

        return res;
    }