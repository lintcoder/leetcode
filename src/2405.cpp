int partitionString(string s) {
        int len = s.size();
        int i = 0;
        int ct = 0;
        
        while (i < len)
        {
            vector<int> flag(26, 0);
            ++ct;
            while (i < len)
            {
                if (flag[s[i]-'a'] == 0)
                {
                    flag[s[i]-'a'] = 1;
                    ++i;
                }
                else
                    break;     
            }
        }
        
        return ct;
    }