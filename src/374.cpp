int guessNumber(int n) {
        int p = 1, q = n;
        while (p < q)
        {
            int mid = p / 2 + q / 2;
            int res = guess(mid);
            if (res == 0)
                return mid;
            else if (res < 0)
                q = mid - 1;
            else
                p = mid + 1;
        }
        return p;
    }