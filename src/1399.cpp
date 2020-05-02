int countLargestGroup(int n) {
        map<int, int> mp;
        int maxnum = 0;
        for (int i = 1; i <= n; ++i)
        {
            int tmp = i, sum = 0;
            while (tmp != 0)
            {
                sum += tmp%10;
                tmp /= 10;
            }

            mp[sum]++;
            if (mp[sum] > maxnum)
                maxnum = mp[sum];
        }
        
        int ct = 0;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter)
            if (iter->second == maxnum)
                ++ct;
        
        return ct;
    }