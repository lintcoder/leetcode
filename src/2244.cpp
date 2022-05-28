int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        int len = tasks.size();
        for (int i = 0; i < len; ++i)
        {
            mp[tasks[i]]++;
        }
        
        int ct = 0;
        for (auto& kv : mp)
        {
            if (kv.second < 2)
                return -1;
            else if (kv.second%2 == 0)
            {
                int n = kv.second/3;
                ct += n%2 == 0 ? n+(kv.second-n*3)/2 : n-1+(kv.second-(n-1)*3)/2;
            }
            else
            {
                int n = kv.second/3;
                ct += n%2 == 1 ? n+(kv.second-n*3)/2 : n-1+(kv.second-(n-1)*3)/2;
            }
        }
        
        return ct;
    }