int countPrimes(int n) {
        if (n <= 2)
            return 0;
        
        int* arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = 1;
        arr[0] = arr[1] = 0;
        
        for (int i = 2; i < n - 2; i += 2)
            arr[i + 2] = 0;

        int lim = sqrt(n - 1);
        int i = 3, j;
        while (i <= lim)
        {
            if (arr[i] == 1)
            {
                int lim2 = (n - 1) / i;
                for (j = i; j <= lim2; ++j)
                    arr[i * j] = 0;

            }
            i += 2;
            while (arr[i] == 0)
                i += 2;
        }
        
        int count = 0;
        for (i = 0; i < n; ++i)
            if (arr[i] == 1)
                ++count;
        delete[] arr;
        
        return count;
    }