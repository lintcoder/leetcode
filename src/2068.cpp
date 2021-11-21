bool checkAlmostEquivalent(string word1, string word2) {
        int len = word1.size();
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);
        
        for (int i = 0; i < len; ++i)
        {
            vec1[word1[i]-'a']++;
            vec2[word2[i]-'a']++;
        }
        
        for (int i = 0; i < 26; ++i)
        {
            if (abs(vec1[i]-vec2[i]) > 3)
                return false;
        }
        
        return true;
    }