int alternateDigitSum(int n) {
        int sum = 0;
        int m = log10(n);
        const bool arr[10] = {true, false, true, false, true, false, true, false, true, false};
        bool flag = arr[m];

        while (n != 0)
        {
            int tmp = n%10;
            if (flag)
                sum += tmp;
            else
                sum -= tmp;
            flag = !flag;
            
            n /= 10;
        }

        return sum;
    }