int reverse(int x) {
        int flag = 1;
        if (x < 0)
        {
            if (x == INT_MIN)
                return 0;
            else
            {
                x = -x;
                flag = -1;
            }
        }
        long long sum = 0;
        while (x > 0)
        {
            sum = sum * 10 + x % 10;
            x /= 10;
            if (sum > INT_MAX)
                return 0;
        }
        return sum * flag;
    }