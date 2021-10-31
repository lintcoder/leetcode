bool isPrefixString(string s, vector<string>& words) {
        int len = words.size();
        int sz = s.size();
        int k = 0;
        for (int i = 0; i < len; ++i)
        {
            int len2 = words[i].size();
            if (len2 > sz-k)
                return false;
            for (int j = 0; j < len2; ++j)
            {
                if (words[i][j] != s[k])
                    return false;
                else
                    ++k;
            }
            if (k == sz)
                break;
        }
        
        if (k < sz)
            return false;
        
        return true;
    }