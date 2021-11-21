int countTriples(int n) {
        int ct = 0;
        vector<int> vec(n, 0);
        for (int i = 1; i <= n; ++i)
            vec[i-1] = i*i;
        
        int lim = int(n/sqrt(2))+1;
        for (int i = 0; i < lim; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                for (int k = j+1; k < n; ++k)
                {
                    if (vec[k] == vec[i]+vec[j])
                    {
                        if (i != j)
                            ct += 2;
                        else
                            ++ct;
                    }
                }
            }  
        }
        
        return ct;
    }