int climbStairs(int n) {
        if (n <= 1)
            return 1;
        if (n == 2)
            return 2;
        int* step = new int[n + 1];
        step[1] = 1;
        step[2] = 2;
        int i = 3;
        while (i <= n)
        {
            step[i] = step[i - 1] + step[i - 2];
            ++i;
        }
        int res = step[n];
        delete step;
        return res;
    }