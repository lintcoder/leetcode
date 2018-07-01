vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; ++i)
        {
            vector<int> rowvec;
            if (i == 1)
                rowvec.push_back(1);
            else if (i == 2)
            {
                rowvec.push_back(1);
                rowvec.push_back(1);
            }
            else
            {
                rowvec.push_back(1);
                for (int j = 1; j < i - 1; ++j)
                    rowvec.push_back(res[i - 2][j - 1] + res[i - 2][j]);
                rowvec.push_back(1);
            }
            res.push_back(rowvec);
        }
    
        return res;
    }