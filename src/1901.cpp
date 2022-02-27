vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> pos(2, -1);
        search(mat, row, col, 0, col-1, pos);
        
        return pos;
    }
    
    bool search(vector<vector<int>>& mat, int row, int col, int lh, int rh, vector<int>& pos)
    {
        if (lh <= rh)
        {
            int mid = (lh+rh)/2;
            for (int i = 0; i < row; ++i)
            {
                bool flag = true;
                if (i > 0)
                    flag &= mat[i][mid] > mat[i-1][mid];
                if (i < row-1)
                    flag &= mat[i][mid] > mat[i+1][mid];
                if (mid > 0)
                    flag &= mat[i][mid] > mat[i][mid-1];
                if (mid < col-1)
                    flag &= mat[i][mid] > mat[i][mid+1];
                if (flag)
                {
                    pos[0] = i;
                    pos[1] = mid;
                    return true;
                }
            }
        
            return search(mat, row, col, lh, mid-1, pos) || search(mat, row, col, mid+1, rh, pos);
        }
        else
            return false;
    }