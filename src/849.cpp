int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        if (len == 1)
        	return 0;

        int maxDist = 0;
        int maxInterval = 0, interval = 0;
        int pos = 0, i = 0;
        if (seats[0] == 0)
        {
        	while (i < len && seats[i] == 0)
        		++i;
        	maxDist = i;
        }
        pos = i;
        ++i;
        while (i < len)
        {
        	if (seats[i] == 1)
        	{
        		interval = i - pos - 1;
        		pos = i;
        		if (interval > maxInterval)
        		{
        			maxInterval = interval;
        		}
        	}
        	++i;
        }
        interval = len-1-pos;
        if (interval > maxDist)
        	maxDist = interval;

        if (maxInterval > 0)
        {
        	maxInterval = maxInterval%2 == 0 ? maxInterval/2 : maxInterval/2 + 1;
        	if (maxInterval > maxDist)
        		maxDist = maxInterval;
        }

        return maxDist;
    }