bool checkValidString(string s) {
        int len = s.size();
        if (len == 0)
        	return true;

        int left = 0, star = 0;
        vector<int> pos1(len, 0);
        vector<int> pos2(len, 0);
        int i = 0, j = 0, k = 0;
        while (i < len)
        {
        	if (s[i] == '(')
        	{
        		++left;
        		pos1[j++] = i;
        	}
        	else if (s[i] == ')')
        	{
        		if (left > 0)
        		{
        			--left;
        			pos1[--j] = -1;
        		}
        		else if (star > 0)
        		{
        			--star;
        			pos2[--k] = -1;
        		}
        		else
        			return false;
        	}
        	else
        	{
        		++star;
        		pos2[k++] = i;
        	}
        	++i;
        }
        if (j > k)
        	return false;

        while (j > 0)
        {
        	int m = pos1[--j];
        	while (pos2[--k] < m);
        	if (k < j)
        		return false;
        }
        return true;
    }