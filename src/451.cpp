string frequencySort(string s) {
        map<char, int> mp;
        for (auto c : s)
        		mp[c]++;

        struct Elem
        {
            char ch;
            int num;
            Elem(char c, int n) : ch(c), num(n){};
        };

        vector<Elem> elemvec;
        for (auto m : mp)
            elemvec.push_back(Elem(m.first, m.second));

        auto cmp = [=](const Elem& a, const Elem& b) {
            return a.num > b.num;
        };
        sort(elemvec.begin(), elemvec.end(), cmp);

        int sz = elemvec.size();
        int pos = 0;
        string str(s.size(), '\0');
        for (int i = 0; i < sz; ++i)
        {
            int n = elemvec[i].num;
            for (int j = pos; j < pos + n; ++j)
                str[j] = elemvec[i].ch;
            pos += n;
        }

        return str;
    }