bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> flag(n, 0);
        for (int i = 0; i < n; ++i)
        {
            flag.assign(n, 0);
            int ct = 0;
            for (int j = 0; j < n; ++j)
            {
                if (flag[matrix[i][j]-1] == 0)
                {
                    flag[matrix[i][j]-1] = 1;
                    ++ct;
                }
            }
            if (ct != n)
                return false;
        }
        
        for (int i = 0; i < n; ++i)
        {
            flag.assign(n, 0);
            int ct = 0;
            for (int j = 0; j < n; ++j)
            {
                if (flag[matrix[j][i]-1] == 0)
                {
                    flag[matrix[j][i]-1] = 1;
                    ++ct;
                }
            }
            if (ct != n)
                return false;
        }
        
        return true;
    }