bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        int max3power = pow(3, (int)(log(INT_MAX) / log(3)));
        return max3power % n == 0;
    }