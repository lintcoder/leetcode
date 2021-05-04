string replaceDigits(string s) {
        int len = s.size();
        for (int i = 0; i < len-1; i += 2)
        {
            s[i+1] = s[i] + (s[i+1]-'0');
        }
        
        return s;
    }