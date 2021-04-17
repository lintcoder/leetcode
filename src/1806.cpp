int reinitializePermutation(int n) {
        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i)
            arr[i] = i;
        
        int ct = 0;
        vector<int> tmp(n, 0);
        while (true)
        {
            ++ct;
            int k = 0;
            for (int i = 0; i < n; ++i)
            {
                if (i%2 == 0)
                    tmp[i] = arr[i/2];
                else
                    tmp[i] = arr[n/2+(i-1)/2];
                if (tmp[i] == i)
                    ++k;
            }
            if (k == n)
                break;
            swap(arr, tmp);
        }
        
        return ct;
    }