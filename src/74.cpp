bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int p = 0, q = m*n-1;
        while (p <= q)
        {
            int mid = (p+q)/2;
            int r = mid/n, c = mid%n;
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target)
                p = mid+1;
            else
                q = mid-1;
        }
        
        return false;
    }