vector<int> findWordsContaining(vector<string>& words, char x) {
        int len = words.size();
        vector<int> res;

        for (int i = 0; i < len; ++i)
        {
            if (words[i].find(x) != string::npos)
                res.push_back(i);
        }

        return res;
    }