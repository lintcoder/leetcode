string mergeAlternately(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        string res(len1+len2, ' ');
        int i = 0, j = 0;
        int k = 0;
        while (i < len1 && j < len2)
        {
            if (k%2 == 0)
                res[k++] = word1[i++];
            else
                res[k++] = word2[j++];
        }
        if (i < len1)
        {
            for (; i < len1; ++i)
                res[k++] = word1[i];
        }
        else if (j < len2)
        {
            for (; j < len2; ++j)
                res[k++] = word2[j];
        }
        
        return res;
    }