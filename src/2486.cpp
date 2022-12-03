int appendCharacters(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        
        int i = 0, j = 0;
        while (i < len1 && j < len2)
        {
            if (s[i] == t[j])
            {
                ++i;
                ++j;
            }
            else
                ++i;
        }
        
        if (j == len2)
            return 0;
        else
            return len2-j;
    }