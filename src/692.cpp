vector<string> topKFrequent(vector<string>& words, int k) {
	    int len = words.size();
	    if (len == 0)
	    	return words;
        map<string, int> mp;
        for (int i = 0; i < len; ++i)
        	mp[words[i]]++;

        struct wordFreq
        {
        	string w;
        	int ct;
        	wordFreq(const string& word = "", int n = 0) : w(word), ct(n){}
        };

        int num = mp.size();
        int j = 0;
        vector<wordFreq> vec(num, wordFreq());
        for (auto iter : mp)
        {
        	vec[j].w = iter.first;
        	vec[j].ct = iter.second;
        	++j;
        }

        auto cmp = [](const wordFreq& a, const wordFreq& b) {
        	return a.ct > b.ct || (a.ct == b.ct && a.w < b.w);
        };

        sort(vec.begin(), vec.end(), cmp);
        vector<string> res(k, "");
        for (int i = 0; i < k; ++i)
        	res[i] = vec[i].w;

        return res;
    }