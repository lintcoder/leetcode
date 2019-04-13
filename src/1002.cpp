vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        int len = A.size();
        if (len == 1)
        {
            transform(A[0].begin(), A[0].end(), back_inserter(res), [](char c) {return string(1, c); });
            return res;
        }
        else
        {
            vector<vector<int>> vec(len, vector<int>(26, 0));
            for (int i = 0; i < len; ++i)
            {
                int sz = A[i].size();
                for (int j = 0; j < sz; ++j)
                    vec[i][A[i][j] - 'a']++;
            }

            for (int i = 0; i < 26; ++i)
            {
                int minval = vec[0][i];
                for (int j = 1; j < len; ++j)
                {
                    if (vec[j][i] < minval)
                        minval = vec[j][i];
                }
                if (minval > 0)
                    res.insert(res.end(), minval, string(1, 'a' + i));
            }

            return res;
        }
    }