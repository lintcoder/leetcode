int percentageLetter(string s, char letter) {
        int len = s.size();
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == letter)
                ++ct;
        }
        
        return ct*100/len;
    }