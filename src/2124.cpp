bool checkString(string s) {
        int len = s.size();
        int i = 0;
        while (i < len && s[i] == 'a')
            ++i;
        if (i >= len-1)
            return true;
        for (; i < len; ++i)
        {
            if (s[i] == 'a')
                return false;
        }
        
        return true;
    }