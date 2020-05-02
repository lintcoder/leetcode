string reformat(string s) {
       int len = s.size();
        if (len == 1)
            return s;
        int digit = 0;
        for (int i = 0; i < len; ++i)
            if (s[i] >= '0' && s[i] <= '9')
                ++digit;
        if (len%2 == 0 && digit != len/2)
            return "";
        else if (len%2 == 1 && (digit < len/2 || digit > len/2+1))
            return "";
        
        string res(len, ' ');
        if (len%2 == 1 && digit == len/2)
        {
            int p = 0, q = 1;
            for (int i = 0; i < len; ++i)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    res[q] = s[i];
                    q += 2;
                }
                else
                {
                    res[p] = s[i];
                    p += 2;
                }
            }
        }
        else
        {
            int p = 0, q = 1;
            for (int i = 0; i < len; ++i)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    res[p] = s[i];
                    p += 2;
                }
                else
                {
                    res[q] = s[i];
                    q += 2;
                }
            }
        }
        
        return res;
    }