bool isBoomerang(vector<vector<int>>& points) {
        if (points[0] == points[1] || points[0] == points[2] || points[1] == points[2])
            return false;
        if (points[0][0] == points[1][0])
            return points[0][0] != points[2][0];
        else if (points[0][1] == points[1][1])
            return points[0][1] != points[2][1];
        else
            return (points[1][1]-points[0][1])*(points[2][0]-points[1][0]) !=
            (points[2][1]-points[1][1])*(points[1][0]-points[0][0]);
    }