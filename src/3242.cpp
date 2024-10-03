class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        pos.assign(n*n, pair(-1,-1));
        for (int i = 0; i < n; ++i)
        {
            elems.push_back(grid[i]);
        }
    }
    
    int adjacentSum(int value) {
        int r = -1, c = -1;
        if (pos[value].first != -1)
        {
            r = pos[value].first;
            c = pos[value].second;
        }
        else
        {
            getPos(value);
            r = pos[value].first;
            c = pos[value].second;
        }

        int sum = 0;
        if (r > 0) sum += elems[r-1][c];
        if (r < n-1) sum += elems[r+1][c];
        if (c > 0) sum += elems[r][c-1];
        if (c < n-1) sum += elems[r][c+1];

        return sum;
    }
    
    int diagonalSum(int value) {
        int r = -1, c = -1;
        if (pos[value].first != -1)
        {
            r = pos[value].first;
            c = pos[value].second;
        }
        else
        {
            getPos(value);
            r = pos[value].first;
            c = pos[value].second;
        }

        int sum = 0;
        if (r > 0 && c > 0) sum += elems[r-1][c-1];
        if (r > 0 && c < n-1) sum += elems[r-1][c+1];
        if (r < n-1 && c > 0) sum += elems[r+1][c-1];
        if (r < n-1 && c < n-1) sum += elems[r+1][c+1];

        return sum;
    }

private:
    vector<vector<int>> elems;
    vector<pair<int,int>> pos;
    int n;

    void getPos(int value)
    {
        int r = -1, c = -1;

        for (int i = 0; r==-1 && i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                if (elems[i][j] == value)
                {
                    r = i;
                    c = j;
                    pos[value].first = r;
                    pos[value].second = c;
                    break;
                }
        }
    }
};