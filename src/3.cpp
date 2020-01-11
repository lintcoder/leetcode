int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len <= 1)
            return len;
        
        map<char, int> pos;
        pos[s[0]] = 0;
        
        int i = 1, tmp = 1;
        int maxlen = 1;
        int index = 0;
        while (i < len)
        {
            if (pos.find(s[i]) == pos.end() || pos[s[i]] == -1)
            {
                ++tmp;
                pos[s[i]] = i;
                ++i;
            }
            else
            { 
                if (tmp > maxlen)
                    maxlen = tmp;
                int t = pos[s[i]];
                for (int j = index; j <=t; ++j)
                    pos[s[j]] = -1;
                tmp = i-t;
                pos[s[i]] = i;
                index = t+1;
                ++i;
            }
        }
        
        if (tmp > maxlen)
            maxlen = tmp;
        
        return maxlen;
    }