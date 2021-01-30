int getMaximumGenerated(int n) {
        if (n <= 1)
            return n;
        
        vector<int> vec(n+1, 0);
        vec[0] = 0;
        vec[1] = 1;
        int i = 2;
        int maxvalue = 1;
        while (i <= n)
        {
            if (i%2 == 0)
                vec[i] = vec[i/2];
            else
                vec[i] = vec[i/2] + vec[i/2+1];
            if (vec[i] > maxvalue)
                maxvalue = vec[i];
            ++i;
        }
        
        return maxvalue;
    }