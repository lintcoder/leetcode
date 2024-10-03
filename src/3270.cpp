int generateKey(int num1, int num2, int num3) {
        int i = 0, k = 1, res = 0;
        while (i < 4)
        {
            int r1 = num1%10;
            int r2 = num2%10;
            int r3 = num3%10;

            int tmp = r1 < r2 ? (r1 < r3 ? r1 : r3) : (r2 < r3 ? r2 : r3);
            res += tmp * k;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
            k *= 10;
            ++i;
        }

        return res;
    }