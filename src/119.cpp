vector<int> getRow(int rowIndex) {
        if (rowIndex < 0)
            return vector<int>();
        vector<int> res[2];
        res[0].resize(rowIndex + 1);
        res[1].resize(rowIndex + 1);
        res[0][0] = res[0][rowIndex] = 1;
        
        int i = 1;
        int pos = 0;
        while (i <= rowIndex)
        {
            pos = 1 - i % 2;
            res[pos][0] = 1;
            for (int j = 0; j < i - 1; ++j)
                res[pos][j + 1] = res[1 - pos][j] + res[1 - pos][j + 1];
            res[pos][i] = 1;
            ++i;
        }
        return res[pos];
    }