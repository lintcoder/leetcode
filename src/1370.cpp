string sortString(string s) {
        int len = s.size();
        if (len == 1)
            return s;
        
        vector<int> num(26, 0);
        for (int i = 0; i < len; ++i)
            num[s[i]-'a']++;
        int k = 0;
        string res(len, ' ');
        while (k < len)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (num[i] > 0)
                {
                    res[k++] = 'a'+i;
                    --num[i];
                }
            }
            
            if (k == len)
                break;
            for (int i = 25; i >= 0; --i)
            {
                if (num[i] > 0)
                {
                    res[k++]  = 'a'+i;
                    --num[i];
                }
            }
        }
        
        return res;
    }