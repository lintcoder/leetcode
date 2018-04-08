int numJewelsInStones(string J, string S) {
        int len1 = J.size();
        int len2 = S.size();
        if (len1 == 0 || len2 == 0)
            return 0;
        set<char> jewels;
        for (int i = 0; i < len1; ++i)
            jewels.insert(J[i]);
        
        int ct = 0;
        for (int i = 0; i < len2; ++i)
            if (jewels.find(S[i]) != jewels.end())
                ++ct;
        
        return ct;
    }