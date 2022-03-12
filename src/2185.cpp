int prefixCount(vector<string>& words, string pref) {
        int len = words.size();
        int n = pref.size();
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            int j = 0;
            for (j = 0; j < n; ++j)
            {
                if (words[i][j] != pref[j])
                    break;
            }
            if (j == n)
                ++ct;
        }
        
        return ct;
    }