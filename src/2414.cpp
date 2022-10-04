int longestContinuousSubstring(string s) {
        int len = s.size();
        
        int i = 1;
        int maxlen = 1, n = 1;
        char c = s[0];
        
        while (i < len)
        {
            if (s[i] == c+1)
            {
                ++n;
            }
            else
            {
                if (n > maxlen)
                    maxlen = n;
                n = 1;
            }
            c = s[i];
            ++i;
        }
        
        if (n > maxlen)
            maxlen = n;
        
        return maxlen;
    }