bool makeEqual(vector<string>& words) {
        int len = words.size();
        int num[26] = {0};
        for (int i = 0; i < len; ++i)
        {
            int sz = words[i].size();
            for (int j = 0; j < sz; ++j)
            {
                ++num[words[i][j]-'a'];
            }
        }
        
        for (int i = 0; i < 26; ++i)
        {
            if (num[i]%len != 0)
                return false;
        }
        
        return true;
    }