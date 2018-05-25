bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
	    if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4)
	    	return false;

        vector<int> point[4];
        bool flag = false;
        if (isparallel(p1, p2, p3, p4))
        {
        	point[0] = p1;
        	point[1] = p2;
        	point[2] = p3;
        	point[3] = p4;
        	flag = true;
        }
        else if (!flag && isparallel(p1, p3, p2, p4))
        {
        	point[0] = p1;
        	point[1] = p3;
        	point[2] = p2;
        	point[3] = p4;
        }
        else
        	return false;

        if ((point[0][0] == point[1][0] && point[0][0] == point[2][0] && point[0][0] == point[3][0]) ||
        	((point[0][1] == point[1][1] && point[0][1] == point[2][1] && point[0][1] == point[3][1])))
        	return false;
        if (point[0][0] == point[1][0])
        {
        	if (point[0][1] == point[2][1])
        	{
        		return abs(point[0][1] - point[1][1]) == abs(point[0][0] - point[2][0]) &&
        		(point[0][1]-point[1][1]) == (point[2][1]-point[3][1]);
        	}
        	else if (point[0][1] == point[3][1])
        	{
        		return abs(point[0][1] - point[1][1]) == abs(point[0][0] - point[3][0]) &&
        		(point[0][1]-point[1][1]) == (point[3][1]-point[2][1]);
        	}
        }
        else
        {
        	if (((point[1][1]-point[0][1])*(point[2][1]-point[0][1]) == -(point[1][0] - point[0][0])*(point[2][0]-point[0][0])) &&
        		((point[0][1]-point[1][1])*(point[3][1]-point[1][1]) == -(point[0][0] - point[1][0])*(point[3][0]-point[1][0])))
        		return distance(point[1], point[0]) == distance(point[2], point[0]);
        	else if (((point[1][1]-point[0][1])*(point[3][1]-point[0][1]) == -(point[1][0] - point[0][0])*(point[3][0]-point[0][0])) &&
        		((point[0][1]-point[1][1])*(point[2][1]-point[1][1]) == -(point[0][0] - point[1][0])*(point[2][0]-point[1][0])))
        		return distance(point[1], point[0]) == distance(point[3], point[0]);
        }

        return false;
    }

    bool isparallel(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        return (p2[1]-p1[1])*(p4[0]-p3[0]) == (p2[0]-p1[0])*(p4[1]-p3[1]);
    }

    int distance(vector<int>& p1, vector<int>&p2)
    {
        return (p2[1]-p1[1])*(p2[1]-p1[1]) + (p2[0]-p1[0])*(p2[0]-p1[0]);
    }