string addSpaces(string s, vector<int>& spaces) {
        int sz = s.size();
        int len = spaces.size();
        int n = sz + len;
        int i = 0, j = 0, k = 0;
        
        string res(n, ' ');
        while (i < n && j < len)
        {
            if (i < spaces[j]+j)
            {
                res[i++] = s[k++];
            }
            else
            {
                ++i;
                ++j;
            }
        }

        if (i < n)
            copy(s.begin()+k, s.end(), res.begin()+i);
        
        return res;
    }