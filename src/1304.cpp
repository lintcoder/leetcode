vector<int> sumZero(int n) {
        vector<int> res(n, 0);
        if (n%2 == 0)
        {
            for (int i = 0; i < n/2; ++i)
            {
                res[i] = i+1;
                res[n-1-i] = -(i+1);
            }    
        }
        else
        {
            res[n/2] = 0;
            for (int i = 0; i < n/2; ++i)
            {
                res[i] = i+1;
                res[n-1-i] = -(i+1);
            }
        }
        
        return res;
    }