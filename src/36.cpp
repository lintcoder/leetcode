bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i)
        {
            int arr1[9] = {0};
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                else if ((board[i][j] >= '1' && board[i][j] <= '9'))
                {
                    int pos1 = board[i][j] - '1';
                    if (arr1[pos1] == 1)
                        return false;
                    else
                        arr1[pos1] = 1;
                }
                else
                    return false;
            }
        }
        
        for (int i = 0; i < 9; ++i)
        {
            int arr2[9] = {0};
            for (int j = 0; j < 9; ++j)
            {
                if (board[j][i] == '.')
                    continue;
                else if ((board[j][i] >= '1' && board[j][i] <= '9'))
                {
                    int pos2 = board[j][i] - '1';
                    if (arr2[pos2] == 1)
                        return false;
                    else
                        arr2[pos2] = 1;
                }
                else
                    return false;
            }
        }
        
        for (int i = 0; i < 9; i = i + 3)
        {
            for (int j = 0; j < 9; j = j + 3)
            {
                int arr[9] = {0};
                for (int m = i; m < i + 3; ++m)
                {
                    for (int n = j; n < j + 3; ++n)
                    {
                        if (board[m][n] == '.')
                            continue;
                        else if (board[m][n] >= '1' && board[i][j] <= '9')
                        {
                            int pos = board[m][n] - '1';
                            if (arr[pos] == 1)
                                return false;
                            else
                                arr[pos] = 1;
                        }
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }