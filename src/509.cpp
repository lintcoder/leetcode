int fib(int N) {
        if (N <= 1)
            return N;
        int a = 0, b = 1;
        int i = 2;
        while (i <= N)
        {
            int t = a+b;
            a = b;
            b = t;
            ++i;
        }
        return b;
    }