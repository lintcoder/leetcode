bool isPerfectSquare(int num) {
        int i = 1, j = num;
        while (i <= j)
        {
            long long mid = i / 2 + j / 2 + (i % 2 && j % 2);
            long long res = mid * mid;
            if (res == num)
                return true;
            else if (res < num)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return false;
    }