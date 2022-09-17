string removeStars(string s) {
        int len = s.size();
        string res(len, ' ');
        
        int i = 0, j = 0;
        while (i < len)
        {
            if(s[i] != '*')
            {
                res[j++] = s[i];
            }
            else
            {
                if(j > 0)
                {
                    --j;
                }
            }
            
            ++i;
        }
        
        res.resize(j);
        
        return res;
    }