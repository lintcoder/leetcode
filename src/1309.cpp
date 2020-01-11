string freqAlphabets(string s) {
        int len = s.size();
        int i = 0;
        string res;
        while (i < len)
        {
            int p = s.find('#', i);
            if (p != -1)
            {
                for (; i < p-2; ++i)
                    res.push_back(s[i]-'1'+'a');
                int t = (s[i]-'0')*10+(s[i+1]-'0');
                res.push_back(t-10+'j');
                i = p+1;
            }
            else
            {
                for (; i < len; ++i)
                    res.push_back(s[i]-'1'+'a');
            }
        }
        
        return res;
    }