vector<string> subdomainVisits(vector<string>& cpdomains) {
        int sz = cpdomains.size();
        map<string, int> mp;
        vector<string> res;

        for (int i = 0; i < sz; ++i)
        {
        	abstractdomains(cpdomains[i], mp);
        }

        for (auto iter : mp)
        	res.push_back(to_string(iter.second) + " " + iter.first);

        return res;
    }

    void abstractdomains(const string& cpdomain, map<string, int>& mp)
    {
        int index = cpdomain.find(' ');
        int ct = stoi(cpdomain.substr(0, index));
        mp[cpdomain.substr(index+1)] += ct;
        while ((index = cpdomain.find('.', index+1)) != string::npos)
        {
            mp[cpdomain.substr(index+1)] += ct;
        }
    }