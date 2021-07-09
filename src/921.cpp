int minAddToMakeValid(string s) {
        int len = s.size();
        if (len <= 1)
            return len;
        int i = 0;
        int left = 0, ct = 0;
        while (i < len)
        {
            if (s[i] == '(')
            {
                ++left;
                ++ct;
            }
            else
            {
                if (left > 0)
                {
                    --left;
                    --ct;
                }
                else
                {
                    ++ct;
                }
            }
            ++i;
        }
        
        return ct;
    }