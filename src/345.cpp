string reverseVowels(string s) {
        int sz = s.size();
        int i = 0, j = sz - 1;
        while (i < j)
        {
            while (i < j && !isvowel(s[i]))
                ++i;
            while (i < j && !isvowel(s[j]))
                --j;
            if (i < j)
            {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                ++i;
                --j;
            }
        }
        
        return s;
    }
    
    bool isvowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }