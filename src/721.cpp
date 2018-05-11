vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int num = accounts.size();
        if (num == 0 || num == 1)
        	return accounts;

        vector<vector<string>> res;
        map<string, vector<int>> mp;

        for (int i = 0; i < num; ++i)
        {
        	int len = accounts[i].size();
        	for (int j = 1; j < len; ++j)
        		mp[accounts[i][j]].push_back(i);
        }

        vector<int> access(num, 0);
        for (int i = 0; i < num; ++i)
        {
        	if (access[i] == 1)
        		continue;
        	access[i] = 1;
        	set<string> account;
        	merge(accounts, access, mp, i, account);

        	vector<string> ac(account.size()+1, "");
        	ac[0] = accounts[i][0];
        	copy(account.begin(), account.end(), ac.begin()+1);
        	sort(ac.begin()+1, ac.end());
        	res.push_back(ac);
        }
	    return res;
    }
    void merge(const vector<vector<string>>& accounts, vector<int>& access, map<string, vector<int>>& mp, int index, set<string>& ac)
    {
        ac.insert(accounts[index].begin()+1, accounts[index].end());
        int len = accounts[index].size();
        for (int i = 1; i < len; ++i)
        {
            int n = mp[accounts[index][i]].size();
            for (int j = 0; j < n; ++j)
            {
                int m = mp[accounts[index][i]][j];
                if (access[m] == 0)
                {
                    access[m] = 1;
                    merge(accounts, access, mp, m, ac);
                }
            }
        }
    }