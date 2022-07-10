string greatestLetter(string s) {
        char digitnum[52] = {0};
        int len = s.size();
        
        for (int i = 0; i < len; ++i)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                digitnum[s[i]-'a'] = 1;
            else
                digitnum[s[i]-'A'+26] = 1;
        }
        for (int i = 25; i >= 0; --i)
        {
            if (digitnum[i] == 1 && digitnum[i+26] == 1)
                return string(1,'A'+i);
        }
        
        return "";
    }