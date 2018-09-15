bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        if (N == 1)
        	return true;

        int* number = new int[N];
        memset(number, 0, N*sizeof(int));
        number[0] = 1;
        int ct = 1;

        deque<int> dq(rooms[0].begin(), rooms[0].end());

        int len = dq.size();
        while (len != 0)
        {
        	for (int i = 0; i < len; ++i)
        	{
        		if (number[dq[i]] == 0)
        		{
        			dq.insert(dq.end(), rooms[dq[i]].begin(), rooms[dq[i]].end());
        			number[dq[i]] = 1;
        			++ct;
        		}
        	}
        	dq.erase(dq.begin(), dq.begin() + len);
        	len = dq.size();
        }
        delete []number;
        return ct == N;
    }