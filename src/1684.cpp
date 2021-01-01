int countConsistentStrings(string allowed, vector<string>& words) {
        int flag[26] = {0};
        int len = allowed.size();
        for (int i = 0; i < len; ++i)
            flag[allowed[i]-'a'] = 1;
        
        int sz = words.size();
        int ct = 0;
        for (int i = 0; i < sz; ++i)
        {
            int n = words[i].size();
            int j = 0;
            for (; j < n; ++j)
            {
                if (flag[words[i][j]-'a'] == 0)
                    break;
            }
            if (j == n)
                ++ct;
        }
        
        return ct;
    }