vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int ct = 1;
        int limit = n%2 == 0 ? n/2 : n/2+1;
        for (int i = 0; i < limit; ++i)
        {
        	for (int j = i; j < n-i; ++j)
        		res[i][j] = ct++;
        	for (int j = i+1; j < n-i; ++j)
        		res[j][n-i-1] = ct++;
        	for (int j = n-i-2; j >= i; --j)
        		res[n-i-1][j] = ct++;
        	for (int j = n-i-2; j >= i+1; --j)
        		res[j][i] = ct++;
        }

        return res;
    }