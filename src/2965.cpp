vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n*n+1;
        int a, b;
        vector<int> vec(m, 0);

        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                vec[grid[r][c]]++;
            }
        }

        for (int i = 1; i < m; ++i)
        {
            if (vec[i] == 2)
                a = i;
            if (vec[i] == 0)
                b = i;
        }

        return {a, b};
    }