int numUniqueEmails(vector<string>& emails) {
        int len = emails.size();
        if (len <= 1)
            return len;

        set<string> uniqueEml;
        for (int i = 0; i < len; ++i)
        {
            int sz = emails[i].size();
            string res(sz, ' ');
            int j = 0, k = 0;
            while (j < sz && emails[i][j] != '@')
            {
                if (emails[i][j] == '+')
                    break;
                else if (emails[i][j] != '.')
                    res[k++] = emails[i][j];
                ++j;
            }
            while (emails[i][j] != '@')
                ++j;
            while (j < sz)
            {
                res[k] = emails[i][j];
                ++j;
                ++k;
            }
            uniqueEml.insert(res.substr(0, k));
        }

        return uniqueEml.size();
    }