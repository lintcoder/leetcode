bool isSubsequence(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        if (len1 > len2)
        	return false;
        else if (len1 == len2)
        	return s == t;
        else
        {
        	int index = 0;
        	int pos = 0;
        	for (int i = 0; i < len1; ++i)
        	{
                if (index == len2)
                    return false;
        		pos = t.find(s[i], index);
        		if (pos == string::npos)
        			return false;
        		index = pos + 1;
        	}

        	return true;
        }
    }