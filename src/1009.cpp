int bitwiseComplement(int N) {
        if (N <= 1)
            return 1-N;
        int ct = 0;
        int i = 0;
        while (N != 0)
        {
            int tmp = N%2;
            if (tmp == 0)
                ct += pow(2, i);
            N /= 2;
            ++i;
        }
        
        return ct;
    }