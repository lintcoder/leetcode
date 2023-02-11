int similarPairs(vector<string>& words) {
        int len = words.size();
        vector<vector<int>> letters(len, vector<int>(27, 0));

        for (int i = 0; i < len; ++i)
        {
            int n = words[i].size();
            for (int j = 0; j < n; ++j)
            {
                if (letters[i][words[i][j]-'a'] == 0)
                {
                    letters[i][words[i][j]-'a'] = 1;
                    letters[i][26]++;
                }
            }
        }

        int ct = 0;
        for (int i = 0; i < len-1; ++i)
        {
            for (int j = i+1; j < len; ++j)
            {
                if (letters[i][26] == letters[j][26])
                {
                    bool flag = true;
                    for (int k = 0; k < 26; ++k)
                    {
                        if (letters[i][k] != letters[j][k])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        ++ct;
                }
            }
        }

        return ct;
    }