bool checkStraightLine(vector<vector<int>>& coordinates) {
        int len = coordinates.size();
        if (len == 2)
            return true;
        
        int dx = coordinates[1][0]-coordinates[0][0], dy = coordinates[1][1]-coordinates[0][1];
        if (dx == 0)
        {
            for (int i = 2; i < len; ++i)
                if (coordinates[i][0] != coordinates[0][0])
                    return false;
            return true;
        }
        else if (dy == 0)
        {
            for (int i = 2; i < len; ++i)
                if (coordinates[i][1] != coordinates[0][1])
                    return false;
            return true;
        }
        else
        {
            for (int i = 2; i < len; ++i)
            {
                int dy1 = coordinates[1][1]-coordinates[0][1];
                int dx2 = coordinates[i][0]-coordinates[1][0];
                int dy2 = coordinates[i][1]-coordinates[1][1];
                int dx1 = coordinates[1][0]-coordinates[0][0];
                if (dy1*dx2 != dy2*dx1)
                    return false;
            }
            
            return true;
        }
    }