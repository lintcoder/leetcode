    int countPrefixSuffixPairs(vector<string>& words) {
        int len = words.size();
        int i, j, k, ct = 0;

        for (i = 0; i < len-1; ++i)
        {
            int len1 = words[i].size();
            for (j = i+1; j < len; ++j)
            {
                int len2 = words[j].size();
                if (len1 > len2)
                    continue;
                for (k = 0; k < len1; ++k)
                {
                    if (words[i][k] != words[j][k] ||
                    words[i][k] != words[j][len2-1-(len1-1-k)])
                        break;
                }

                if (k == len1)
                    ++ct;
            }
        }

        return ct;
    }