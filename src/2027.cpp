int minimumMoves(string s) {
        int len = s.size();
        int i = 0;
        int ct = 0;
        while (i < len)
        {
            if (s[i] == 'O')
                ++i;
            else
            {
                ++ct;
                i += 3;
            }
        }
        
        return ct;
    }