bool checkOnesSegment(string s) {
        int len1 = 0;
        int len = s.size();
        if (len == 1)
            return true;
        
        int i = 1;
        while (i < len && s[i] == '1')
            ++i;
        if (i == len)
            return true;
        while (i < len && s[i] == '0')
            ++i;
        return i == len;
    }