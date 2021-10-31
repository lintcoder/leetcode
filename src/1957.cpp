string makeFancyString(string s) {
        int len = s.size();
        if (len < 3)
            return s;
        
        stringstream ss;
        int ct = 1;
        int lastchar = s[0];
        int i = 1;
        ss << s[0];
        while (i < len)
        {
            if (s[i] == lastchar)
            {
                ++ct;
                if (ct < 3)
                    ss << s[i];
                ++i;
            }
            else
            {
                ct = 1;
                lastchar = s[i];
                ss << s[i];
                ++i;
            }
        }
        
        return ss.str();
    }