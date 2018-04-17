bool judgeSquareSum(int c) {
        int lim = sqrt(c/2);
        for (int i = 0; i <= lim; ++i)
        {
            int remain = c - i*i;
            int tmp = sqrt(remain);
            if (tmp * tmp == remain)
                return true;
        }
        return false;
    }