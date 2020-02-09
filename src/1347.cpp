int minSteps(string s, string t) {
        vector<int> ct1(26, 0);
        vector<int> ct2(26, 0);
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            ct1[s[i]-'a']++;
            ct2[t[i]-'a']++;
        }
        
        for (int i = 0; i < 26; ++i)
        {
            if (ct1[i] > 0 && ct2[i] > 0)
                len -= min(ct1[i], ct2[i]);
        }
        
        return len;
    }