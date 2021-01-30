string modifyString(string s) {
        int len = s.size();
        int i = 0;
        if (s[i] == '?')
        {
            if (i+1 < len && s[i+1] != '?')
                s[i] = s[i+1] < 'z' ? s[i+1]+1 : 'a';
            else
                s[i] = 'a';
        }
        ++i;
        
        while (i < len)
        {
            if (s[i] == '?')
            {
                if (i+1 < len && s[i+1] != '?')
                {
                    char c = s[i-1] < s[i+1] ? s[i-1] : s[i+1];
                    if (c == 'z')
                        s[i] = 'a';
                    else
                        s[i] = c+1 != s[i-1]+s[i+1]-c ? c+1 : (c+1 < 'z' ? c+2 : 'a');
                }
                else
                    s[i] = s[i-1] < 'z' ? s[i-1]+1 : 'a';
            }
            ++i;
        }
        
        return s;
    }