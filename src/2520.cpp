int countDigits(int num) {
        int ct = 0;
        int val = num;
        while (val != 0)
        {
            int t = val%10;
            if (t != 0 && num%t == 0)
                ++ct;
            val /= 10;
        }

        return ct;
    }