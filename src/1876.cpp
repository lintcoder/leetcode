int countGoodSubstrings(string s) {
        int len = s.size();
        if (len < 3)
            return 0;
        
        int ct = 0;
        int a = s[0], b = s[1];
        
        int i = 2;
        while (i < len)
        {
            if (a != b)
            {
                if (s[i] != a && s[i] != b)
                {
                    a = b;
                    b = s[i];
                    ++ct;
                    ++i;
                }
                else if (s[i] == a)
                {
                    a = b;
                    b = s[i];
                    ++i;
                }
                else
                {
                    a = b;
                    if (i+1 >= len)
                        break;
                    b = s[i+1];
                    i += 2;
                }
            }
            else
            {
                if (i+1 >= len)
                    break;
                b = s[i];
                ++i;
            }
        }
        
        return ct;
    }