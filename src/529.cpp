vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        int posR = click[0], posC = click[1];
        if (board[posR][posC] == 'M')
        {
            board[posR][posC] = 'X';
            return board;
        }
        else
        {
            int row = board.size(), col = board[0].size();
            updateAdjacentSquare(board, posR, posC, row, col);
            return board;
        }   
    }

    void updateAdjacentSquare(vector<vector<char>>& board, int r, int c, int row, int col)
    {
        if (board[r][c] == 'E')
        {
            int num = 0;
            if (checkAdjacent(board, r, c, row, col, num))
            {
                board[r][c] = num + '0';
                return;
            }
            else
            {
                board[r][c] = 'B';
                if (r > 0)
                    updateAdjacentSquare(board, r-1, c, row, col);
                if (r < row - 1)
                    updateAdjacentSquare(board, r+1, c, row, col);
                if (c > 0)
                    updateAdjacentSquare(board, r, c-1, row, col);
                if (c < col - 1)
                    updateAdjacentSquare(board, r, c+1, row, col);
                if (r > 0 && c > 0)
                    updateAdjacentSquare(board, r-1, c-1, row, col);
                if (r > 0 && c < col - 1)
                    updateAdjacentSquare(board, r-1, c+1, row, col);
                if (r < row - 1 && c > 0)
                    updateAdjacentSquare(board, r+1, c-1, row, col);
                if (r < row - 1 && c < col - 1)
                    updateAdjacentSquare(board, r+1, c+1, row, col);
            }
        }
    }

    bool checkAdjacent(vector<vector<char>>& board, int r, int c, int row, int col, int& num)
    {
        if (r > 0 && board[r - 1][c] == 'M')
            num++;
        if (r < row - 1 && board[r + 1][c] == 'M')
            num++;
        if (c > 0 && board[r][c - 1] == 'M')
            num++;
        if (c < col - 1 && board[r][c + 1] == 'M')
            num++;
        if (r > 0 && c > 0 && board[r-1][c-1] == 'M')
            num++;
        if (r > 0 && c < col - 1 && board[r-1][c+1] == 'M')
            num++;
        if (r < row - 1 && c > 0 && board[r+1][c-1] == 'M')
            num++;
        if (r < row - 1 && c < col - 1 && board[r+1][c+1] == 'M')
            num++;

        return num != 0;
    }