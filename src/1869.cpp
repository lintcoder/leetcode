bool checkZeroOnes(string s) {
        int len1 = 0;
        int len0 = 0;
        int maxlen1 = 0, maxlen0 = 0;
        
        int len = s.size();
        int i = 1;
        
        if (len == 0)
            return false;
        if (s[0] == '1')
            len1 = 1;
        else
            len0 = 1;
        
        while (i < len)
        {
            if (s[i] == '1')
            {
                if (len1 > 0)
                    ++len1;
                else
                {
                    if (len0 > maxlen0)
                        maxlen0 = len0;
                    len0 = 0;
                    len1 = 1;
                }
            }
            else
            {
                if (len0 > 0)
                    ++len0;
                else
                {
                    if (len1 > maxlen1)
                        maxlen1 = len1;
                    len0 = 1;
                    len1 = 0;
                }
            }
            ++i;
        }
        
        if (len1 > 0 && len1 > maxlen1)
            maxlen1 = len1;
        if (len0 > 0 && len0 > maxlen0)
            maxlen0 = len0;
    
        return maxlen1 > maxlen0;
    }