vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int limity = 1000;
        for (int i = 1; i <= 1000; ++i)
        {
            int p = 1, q = limity;
            while (p <= q)
            {
                int mid = (p+q)/2;
                int tmp = customfunction.f(i, mid);
                if (tmp == z)
                {
                    res.push_back({i, mid});
                    limity = mid;
                    break;
                }    
                else if (tmp < z)
                    p = mid+1;
                else
                    q = mid-1;
            }
        }
        
        return res;
    }