void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        if (len <= 1)
            return;
        if (len == 2)
        {
            if (arr[0] == 0)
                arr[1] = 0;
            return;
        }
        
        int pos = 0;
        int ct = 0;
        int i = 0;
        while (i < len && ct < len)
        {
            if (arr[i] != 0)
                ++ct;
            else
                ct += 2;
            ++i;
        }
        if (i == len)
            return;
        --i;
        int j = len-1;
        if (ct == len && arr[i] == 0)
        {
            arr[j] = 0;
            arr[j-1] = 0;
            j -= 2;
            --i;
        }
        else
        {
            arr[j] = arr[i];
            --j;
            --i;
        }
        
        while (j >= 0 && i >= 0)
        {
            if (arr[i] != 0)
                arr[j--] = arr[i];
            else
            {
                arr[j] = 0;
                arr[j-1] = 0;
                j -= 2;
            }
            --i;
        }
    }