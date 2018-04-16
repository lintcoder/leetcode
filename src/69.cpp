int mySqrt(int x) {
        if (x < 0)
            return -1;
        if (x <= 1)
            return x;
        int p = 1, q = x;
        while (p < q - 1)
        {
            long long mid = p/2 + q/2 + (p%2 && q%2);
            long long res = mid * mid;
            if (res == x)
                return mid;
            else if (res < x)
                p = mid;
            else
                q = mid - 1;
        }
        if (q <= x/q)
            return q;
        else    
            return p;
    }