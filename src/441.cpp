int arrangeCoins(int n) {
        if (n <= 0)
        return 0;
        int lim = sqrt(2) * sqrt(n) - 1;
        int num = 0;
        if (lim % 2 == 1)
            num = (1 + lim) / 2 * lim;
        else
            num = lim / 2 * (1 + lim);
        while (n - num >= lim + 1)
        {
            ++lim;
            n -= num;
        }
        return lim;
    }