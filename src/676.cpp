public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        if (!mdict.empty())
            mdict.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        int len = dict.size();
        for (int i = 0; i < len; ++i)
        {
            int sz = dict[i].size();
            if (mdict.find(sz) == mdict.end())
                mdict.insert(pair<int, list<string>>(sz, list<string>(1, dict[i])));
            else
                mdict[sz].push_back(dict[i]);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int len = word.size();
        if (mdict.find(len) == mdict.end())
            return false;
        else
        {
            for (auto iter = mdict[len].begin(); iter != mdict[len].end(); ++iter)
                if (check(word, *iter, len))
                    return true;
            return false;
        }
    }

private:
    map<int, list<string>> mdict;
    bool check(const string& a, const string& b, int len)
    {
        int ct = 0;
        for (int i = 0; i < len; ++i)
            if (a[i] != b[i])
            {
                ++ct;
                if (ct == 2)
                    return false;
            }
        return ct == 1;
    }