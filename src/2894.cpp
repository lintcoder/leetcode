int differenceOfSums(int n, int m) {
        int res = (1+n)*n/2;
        if (m > n)
            return res;
        int v = n, sum = 0;
        while (v%m != 0)
            --v;
        while (v > 0)
        {
            res -= v;
            sum += v;
            v -= m;
        }

        return res-sum;
    }