bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if (row == 0)
            return word == "";
        int col = board[0].size();
        
        if (col == 0)
            return word == "";
        int total = row*col;
        
        int sz = word.size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == word[0])
                {
                    vector<int> flag(total, 0);
                    flag[i*col+j] = 1;
                    bool res = search(board, row, col, i, j, 1, sz, word, flag);
                    if (res)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool search(const vector<vector<char>>& board, int row, int col, int r, int c, int ct, int sz, const string& word, vector<int>& flag)
    {
        if (ct == sz)
            return true;
        bool res = false;
        if (r > 0 && flag[(r-1)*col+c] == 0 && board[r-1][c] == word[ct])
        {
            vector<int> flag1(flag);
            flag1[(r-1)*col+c] = 1;
            res = search(board, row, col, r-1, c, ct+1, sz, word, flag1);
        }    
        if (!res && r < row-1 && flag[(r+1)*col+c] == 0 && board[r+1][c] == word[ct])
        {
            vector<int> flag1(flag);
            flag1[(r+1)*col+c] = 1;
            res = search(board, row, col, r+1, c, ct+1, sz, word, flag1);
        }
        if (!res && c > 0 && flag[r*col+c-1] == 0 && board[r][c-1] == word[ct])
        {
            vector<int> flag1(flag);
            flag1[r*col+c-1] = 1;
            res = search(board, row, col, r, c-1, ct+1, sz, word, flag1);
        }
        if (!res && c < col-1 && flag[r*col+c+1] == 0 && board[r][c+1] == word[ct])
        {
            vector<int> flag1(flag);
            flag1[r*col+c+1] = 1;
            res = search(board, row, col, r, c+1, ct+1, sz, word, flag1);
        }
        
        return res;
    }