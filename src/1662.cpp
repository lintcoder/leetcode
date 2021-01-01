bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
        int len1 = word1.size();
        int len2 = word2.size();
        
        int sz1 = word1[0].size();
        int sz2 = word2[0].size();
        while (i1 < len1 && i2 < len2)
        {
            while (j1 < sz1 && j2 < sz2)
            {
                if (word1[i1][j1] != word2[i2][j2])
                    return false;
                ++j1;
                ++j2;
            }
            if (j1 == sz1)
            {
                ++i1;
                if (i1 < len1)
                {
                    sz1 = word1[i1].size();
                    j1 = 0;
                }
            }
            if (j2 == sz2)
            {
                ++i2;
                if (i2 < len2)
                {
                    sz2 = word2[i2].size();
                    j2 = 0;
                }
            }
        }
        
        return (i1 == len1 && i2 == len2);
    }