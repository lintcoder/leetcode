bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        int limit = sizeof(int) * 8;
        int ct = 0;
        for (int i = 0; i < limit; ++i)
        {
            if (((n >> i) & 1) == 1)
            {
                ++ct;
                if (ct > 1)
                    return false;
            }
        }
        return true;
    }