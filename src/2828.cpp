bool isAcronym(vector<string>& words, string s) {
        int len = words.size();
        int sz = s.size();
        if (len != sz)
            return false;
        
        for (int i = 0; i < len; ++i)
        {
            if(words[i][0] != s[i])
                return false;
        }

        return true;
    }