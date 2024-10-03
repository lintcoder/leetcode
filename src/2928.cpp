int distributeCandies(int n, int limit) {
        int ct = 0;
        for (int i = 0; i <= n; ++i)
        {
            if (i > limit)
                break;
            for (int j = 0; j <= n-i; ++j)
            {
                if (j > limit)
                    break;
                if (n-i-j > limit)
                    continue;
                else
                    ++ct;
            }
        }

        return ct;
    }