int countPrefixes(vector<string>& words, string s) {
        int len = words.size();
        int lens = s.size();
        int ct = 0, j;
        for (int i = 0; i < len; ++i)
        {
            int sz = words[i].size();
            if (sz <= lens)
            {
                for (j = 0; j < sz; ++j)
                {
                    if (words[i][j] != s[j])
                        break;
                }
                if(j == sz)
                    ++ct;
            }
        }
        
        return ct;
    }