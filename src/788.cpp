const int nogood[10] = {1, 2, 3, 3, 3, 4, 5, 5, 6, 7};
const int good[10] = {4, 4, 7, 0, 0, 7, 7, 0, 4, 7};
const int flag[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
int rotatedDigits(int N) {
        int n = 0, num = N;
        while (num > 0)
        {
            num /= 10;
            ++n;
        }
        int ct = 0;
        if (n == 1)
            return count1(N);
        else if (n == 2)
            return count2(N);
        else if (n == 3)
            return count3(N);
        else if (n == 4)
            return count4(N);
        else
            return count4(9999);
    }
    
    int count1(int n)
    {
        if (n < 2)
            return 0;
        else if (n < 5)
            return 1;
        else if (n < 6)
            return 2;
        else if (n < 9)
            return 3;
        else
            return 4;
    }
    
    int count2(int n)
    {
        int digit = n/10;
        int ct = 0;
        for (int i = 0; i < digit; ++i)
            ct += good[i];
        if (flag[digit] == 0)
            ct += count1(n%10);
        else if (flag[digit] == 1)
            ct += nogood[n%10];
        return ct;
    }
    
    int count3(int n)
    {
        int digit = n/100;
        int ct = 0;
        for (int i = 0; i < digit; ++i)
        {
            if (flag[i] == 0)
                ct += 40;
            else if (flag[i] == 1)
                ct += 49;
        }
        if (flag[digit] == 0)
            ct += count2(n%100);
        else if (flag[digit] == 1)
        {
            for (int i = 0; i < n%100/10; ++i)
                if (flag[i] != -1)
                    ct += 7;
            digit = n%100/10;
            if (flag[digit] != -1)
                ct += nogood[n%10];
        }
        return ct;
    }

    int count4(int n)
    {
        int digit = n/1000;
        int ct = 0;
        int tmp = count3(999);
        for (int i = 0; i < digit; ++i)
        {
            if (flag[i] == 0)
                ct += tmp;
            else if (flag[i] == 1)
                ct += 343;
        }
        if (flag[digit] == 0)
            ct += count3(n%1000);
        else if (flag[digit] == 1)
        {
            digit = n%1000/100;
            for (int i = 0; i < digit; ++i)
                if (flag[i] != -1)
                    ct += 49;
            if (flag[digit] != -1)
            {
                digit = n%100/10;
                for (int i = 0; i < digit; ++i)
                    if (flag[i] != -1)
                        ct += 7;
                if (flag[digit] != -1)
                    ct += nogood[n%10];
            }
        }

        return ct;
    }