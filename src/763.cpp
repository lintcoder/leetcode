vector<int> partitionLabels(string S) {
	    vector<int> firstindex(26, -1);
	    vector<int> lastindex(26, -1);
	    vector<int> res;
        int len = S.size();
        if (len == 0)
        	return res;

        for (int i = 0; i < len; ++i)
        {
        	if (firstindex[S[i]-'a'] == -1)
        	{	
        		firstindex[S[i]-'a'] = i;
        		lastindex[S[i]-'a'] = i;
        	}
        	else
        		lastindex[S[i]-'a'] = i;
        }
        vector<pair<int,int>> letterrange;
        for (int i = 0; i < 26; ++i)
        {
        		if (firstindex[i] != -1)
        			letterrange.push_back(make_pair(firstindex[i], lastindex[i]));
        }

        auto cmp = [](const pair<int,int>& l, const pair<int,int>& r) {
        		return l.first < r.first;
        };
        sort(letterrange.begin(), letterrange.end(), cmp);

        int i = 1;
        int lpos = letterrange[0].first, rpos = letterrange[0].second;
        len = letterrange.size();
        while (i < len)
        {
        	if (letterrange[i].first < rpos)
        	{
        		rpos = letterrange[i].second > rpos ? letterrange[i].second : rpos;
        	}
        	else
        	{
        		res.push_back(rpos-lpos+1);
        		lpos = letterrange[i].first;
        		rpos = letterrange[i].second;
        	}
        	++i;
        }
        res.push_back(rpos-lpos+1);
        return res;
    }