int firstBadVersion(int n) {
        if (n < 1)
            return 0;
        int p = 1, q = n;
        while (p < q)
        {
            int mid = p / 2 + q / 2;
            if (isBadVersion(mid))
                q = mid;
            else
                p = mid + 1;
        }
        return p;
    }