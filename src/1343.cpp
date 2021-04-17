int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int len = arr.size();
        int sum = 0;
        int ct = 0;
        const int thres = k*threshold;
        
        for (int i = 0; i < k; ++i)
            sum += arr[i];
        if (sum >= thres)
            ++ct;
        int j = k;
        while (j < len)
        {
            sum += arr[j]-arr[j-k];
            if (sum >= thres)
                ++ct;
            ++j;
        }
        
        return ct;
    }