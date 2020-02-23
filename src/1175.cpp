int numPrimeArrangements(int n) {
        if (n == 1)
            return 1;
        
        int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,
                      67,71,73,79,83,89,97};
        int len = sizeof(prime)/sizeof(prime[0]);    
        int ct = 0;
        for (int i = 0; i < len; ++i)
        {
            if (prime[i] <= n)
                ++ct;
            else
                break;
        }
 
        int mod = 1e9+7;
        long long res = 1;
        for (int i = 1; i <= ct; ++i)
        {
            res = (res*i)%mod;
        }
        ct = n-ct;
        for (int i = 1; i <= ct; ++i)
        {
            res = (res*i)%mod;
        }
        
        return res;
    }