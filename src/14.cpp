string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        int sz = strs.size();
        if (sz == 0)
            return prefix;
        else if (sz == 1)
            return strs[0];
        else
        {
            int minlen = strs[0].size();
            for (int i = 1; i < sz; ++i)
            {
                int len = strs[i].size();
                if (len < minlen)
                    minlen = len;
            }
            
            int i, j = 0;
            while (j < minlen)
            {
                char c = strs[0][j];
                for (i = 1; i < sz; ++i)
                {
                    if (strs[i][j] != c)
                        break;
                }
                if (i != sz)
                    break;
                else
                {
                    prefix.push_back(c);
                    ++j;
                }
            }
            
            return prefix;
        }
    }