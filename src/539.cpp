int findMinDifference(vector<string>& timePoints) {
		int len = timePoints.size();
		if (len <= 1)
			return 0;
        sort(timePoints.begin(), timePoints.end());
        int mindiff = calcudiff(timePoints[0], timePoints[1]);
        int diff;
        for (int i = 2; i < len; ++i)
        {
        	diff = calcudiff(timePoints[i - 1], timePoints[i]);
        	if (diff < mindiff)
        		mindiff = diff;
        }
        diff = calcudiff(timePoints[len - 1], timePoints[0]) + 1440;
        if (diff < mindiff)
            mindiff = diff;

        return mindiff;
    }

    int calcudiff(const string& t1, const string& t2)
    {
        int h1 = stoi(t1.substr(0, 2));
        int h2 = stoi(t2.substr(0, 2));
        int min1 = stoi(t1.substr(3));
        int min2 = stoi(t2.substr(3));

        return h2*60 + min2 - h1*60 - min1;
    }