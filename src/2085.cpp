int countWords(vector<string>& words1, vector<string>& words2) {
        int len1 = words1.size();
        int len2 = words2.size();
        
        map<string, int> mp1, mp2;
        for (int i = 0; i < len1; ++i)
            mp1[words1[i]]++;
        for (int i = 0; i < len2; ++i)
            mp2[words2[i]]++;
        
        int ct = 0;
        for (auto iter = mp1.begin(); iter != mp1.end(); ++iter)
        {
            if (iter->second == 1 && mp2[iter->first] == 1)
            {
                ++ct;
            }
        }
        
        return ct;
    }