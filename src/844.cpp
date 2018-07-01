bool backspaceCompare(string S, string T) {
        int len1 = S.size();
        int len2 = T.size();
        if (len1 == 0 && len2 == 0)
        	return true;

        string res1, res2;
        int i = 0, j = 0;
        while (i < len1 && S[i] == '#')
        	++i;
        while (j < len2 && T[j] == '#')
        	++j;
        if (i == len1 && j == len2)
        	return true;
        else if (i == len1 && j != len2)
        {
        	return isblank(T, j, len2);
        }
        else if (i != len1 && j == len2)
        {
        	return isblank(S, i, len1);
        }
        else
        {
        	string res1(len1-i, S[i]), res2(len2-j, T[j]);
        	++i;
        	++j;
        	int pos1 = 1, pos2 = 1;
        	while (i < len1)
        	{
        		if (isalpha(S[i]))
        		{
        			res1[pos1] = S[i];
        			++pos1;
        		}
        		else
        		{
        			if (pos1 > 0)
        				--pos1;
        		}
        		++i;
        	}
        	while (j < len2)
        	{
        		if (isalpha(T[j]))
        		{
        			res2[pos2] = T[j];
        			++pos2;
        		}
        		else
        		{
        			if (pos2 > 0)
        				--pos2;
        		}
        		++j;
        	}
        	return res1.substr(0, pos1) == res2.substr(0, pos2);
        }
    }

    bool isblank(const string& str, int pos, int len)
    {
        int ct = 0;
        for (int i = pos; i < len; ++i)
            if (isalpha(str[i]))
                ++ct;
            else if (ct > 0)
                --ct;
        return ct == 0;
    }