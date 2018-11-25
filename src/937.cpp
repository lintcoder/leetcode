vector<string> reorderLogFiles(vector<string>& logs) {
        int len = logs.size();
        if (len <= 1)
        return logs;

        map<string, string> letter;
        for (int i = 0; i < len; ++i)
        {
            int index = logs[i].find(' ') + 1;
            letter[logs[i]] = logs[i].substr(index);
        }

        auto cmp = [=](string& a, string& b) {
            char c1 = letter[a][0];
            char c2 = letter[b][0];
            if (isdigit(c2))
            return true;
            else if (isdigit(c1))
            return false;
            else
            return letter[a] < letter[b];
        };

        sort(logs.begin(), logs.end(), cmp);
        return logs;
    }