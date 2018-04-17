int lengthOfLastWord(string s) {
        int sz = s.size();
        int len = 0;
        int p = 0, q = 0;
        while (p < sz)
        {
            p = s.find_first_not_of(' ', q);
            if (p == string::npos)
                break;
            q = s.find(' ', p);
            if (q == string::npos)
                break;
            len = q - p;
        }
        if (q == string::npos)
            len = sz - p;
        return len;
    }