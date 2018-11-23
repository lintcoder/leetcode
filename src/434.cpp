int countSegments(string s) {
        int sz = s.size();
        int i = 0, ct = 0;
        while (i < sz)
        {
            i = s.find_first_not_of(" \t\n", i);
            if (i == string::npos)
                break;
            i = s.find_first_of(" \t\n", i + 1);
            ++ct;
        }
        return ct;
    }