bool halvesAreAlike(string s) {
        int len = s.size();
        int n1 = 0, n2 = 0;
        for (int i = 0; i < len/2; ++i)
        {
            switch(tolower(s[i]))
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    ++n1;                    
            }
        }
        for (int i = len/2; i < len; ++i)
        {
            switch(tolower(s[i]))
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    ++n2;                    
            }
        }
        
        return n1 == n2;
    }