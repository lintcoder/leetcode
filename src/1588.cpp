int sumOddLengthSubarrays(vector<int>& arr) {
        int len = arr.size();
        int res = 0;
        for (int i = 1; i <= len ; i += 2)
        {
            int tmp = 0;
            for (int j = 0; j < i; ++j)
                tmp += arr[j];
            
            res += tmp;
            
            for (int j = 0; j < len-i; ++j)
            {
                tmp -= arr[j];
                tmp += arr[j+i];
                res += tmp;
            }
        }
        
        return res;
    }