int xorOperation(int n, int start) {
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int tmp = start + 2*i;
            res ^= tmp;
        }
        
        return res;
    }