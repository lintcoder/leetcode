char repeatedCharacter(string s) {
        int num[26] = {0};
        int len = s.size();
        
        char c;
        for (int i = 0; i < len; ++i)
        {
            if (num[s[i]-'a'] == 1)
            {
                c = s[i];
                break;
            }
            ++num[s[i]-'a'];
        }
        
        return c;
    }