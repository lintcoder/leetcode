int findNthDigit(int n) {
        if (n <= 0)
        return 0;
        long long num = 1, ct = 1;
        int predigits = 0, count = 9;
        long long digits = 9 * num * ct;
        while (n >= digits)
        {
            n -= digits;
            num *= 10;
            ++ct;
            predigits += count;
            count *= 10;
            digits = 9 * num * ct;
        }
    
        if (n == 0)
            return 9;
        else
        {
            int remain = n % ct;
            int val = n / ct;
            if (remain == 0)
                return (predigits + val) % 10;
            else
                return selectNthDigit(predigits + val + 1, remain, ct);
        }
    }
    
    int selectNthDigit(int num, int pos, int totaldigit)
    {
        int n = totaldigit - pos;
        while (n > 0)
        {
            num /= 10;
            --n;
        }
        return num % 10;
    }