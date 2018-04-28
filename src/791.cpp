string customSortString(string S, string T) {
        int len = S.size();
        if (len <= 1)
        	return T;

        vector<int> prio(26, -1);
        for (int i = 0; i < len; ++i)
        	prio[S[i]-'a'] = i;

        auto cmp = [=](char a, char b) {
        	return prio[a-'a'] < prio[b-'a'];
        };

        sort(T.begin(), T.end(), cmp);
        return T;
    }