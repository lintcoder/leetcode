int numberOfBeams(vector<string>& bank) {
        int row = bank.size();
        if (row == 1)
            return 0;
        int col = bank[0].size();
        vector<int> devices(row, 0);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (bank[i][j] == '1')
                    devices[i]++;
            }
        }
        
        int i = 0, j = 1;
        int res = 0;
        while (i < row-1 && devices[i] == 0)
            ++i;
        while (i < row-1)
        {
            j = i+1;
            while (j < row && devices[j] == 0)
                ++j;
            if (j == row)
                break;
            res += devices[i]*devices[j];
            i = j;
        }
        
        return res;
    }