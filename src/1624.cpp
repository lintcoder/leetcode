int maxLengthBetweenEqualCharacters(string s) {
        vector<vector<int>> vec(26, vector<int>(2, -1));
        int len = s.size();
        
        for (int i = 0; i < len; ++i)
        {
            if (vec[s[i]-'a'][0] == -1)
                vec[s[i]-'a'][0] = i;
            else
                vec[s[i]-'a'][1] = i;
        }
        
        int maxdelta = 0;
        for (int i = 0; i < 26; ++i)
        {
            int delta = vec[i][1]-vec[i][0];
            if (vec[i][1] != -1 && delta > maxdelta)
                maxdelta = delta;
        }
        
        return maxdelta-1;
    }