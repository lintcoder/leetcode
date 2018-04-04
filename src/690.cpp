int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> mp;
        int len = employees.size();
        for (int i = 0; i < len; ++i)
        	mp.insert(pair<int, Employee*>(employees[i]->id, employees[i]));

        deque<Employee*> dq;
        dq.push_back(mp[id]);
        int sum = 0;
        while (!dq.empty())
        {
        	int sz = dq.size();
        	for (int i = 0; i < sz; ++i)
        	{
        		sum += dq[i]->importance;
        		len = dq[i]->subordinates.size();
        		for (int j = 0; j < len; ++j)
        			dq.push_back(mp[dq[i]->subordinates[j]]);
        	}
        	dq.erase(dq.begin(), dq.begin() + sz);
        }

        return sum;
    }