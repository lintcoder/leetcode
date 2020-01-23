int uniquePaths(int m, int n) {
        vector<vector<int>> path(m, vector<int>(n, 0));
        
        return search(0, 0, m, n, path);
    }
    
    int search(int p, int q, int m, int n, vector<vector<int>>& path)
    {
        if (p < m-1 && q < n-1)
        {
            if (path[p][q] == 0)
            {
                int t = search(p+1, q, m, n, path) + search(p, q+1, m, n, path);
                path[p][q] = t;
                
                return t;
            }
            else
                return path[p][q];
        }
        else
            return 1;
    }