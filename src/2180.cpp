int countEven(int num) {
        int ct = 0;
        for (int i = 1; i <= num; ++i)
        {
            int n = i;
            int sum = 0;
            while (n > 0)
            {
                sum += n%10;
                n /= 10;
            }
            if (sum%2 == 0)
                ++ct;
        }
        
        return ct;
    }