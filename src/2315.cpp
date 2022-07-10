int countAsterisks(string s) {
        int len = s.size();
        int i = 0;
        int ct = 0;
        bool flag = false;
        
        while (i < len)
        {
            if (flag == false)
            {
                if (s[i] == '*')
                    ++ct;
                else if (s[i] == '|')
                    flag = true;
                ++i;
            }
            else
            {
                if (s[i] == '|')
                    flag = false;
                ++i;
            }
        }
        
        return ct;
    }