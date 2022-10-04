int commonFactors(int a, int b) {
        int c;
        if (a < b)
            c = a;
        else
            c = b;
        
        int lim = sqrt(c);
        int ct = 1;
        
        for (int i = 2; i <= c; ++i)
        {
            if ((a%i == 0) && (b%i == 0))
                ++ct;
        }
        
        return ct;
    }