int numFriendRequests(vector<int>& ages) {
        int len = ages.size();
        if (len <= 1)
        	return 0;

        sort(ages.begin(), ages.end());
        int i = len-1;
        int ct = 0;
        while (i > 0)
        {
        	int limit = ages[i]*0.5 + 7;
        	int last_age = ages[i];
        	auto iter = upper_bound(ages.begin(), ages.begin()+i, limit);
        	
        	if (iter != ages.begin()+i)
        	{
        		int n = i - (iter-ages.begin());
        		ct += n;
        		int tmp = i;
        		while (--i >= 0 && ages[i] == last_age)
        		{
        			ct += n-1;
        			n--;
        		}
        		ct += (tmp+1 - (i+1))*(tmp-(i+1))/2;
        	}
        	else
        	{
        		while (--i >= 0 && ages[i] == last_age);
        	}
        }

        return ct;
    }