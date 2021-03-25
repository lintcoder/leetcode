int findKthPositive(vector<int>& arr, int k) {
        int flag[2000] = {0};
        int len = arr.size();
        for (int i = 0; i < len; ++i)
            flag[arr[i]-1] = 1;
        
        int ct = 0;
        for (int i = 0; i < 2000; ++i)
        {
            if (flag[i] == 0)
            {
                ++ct;
                if (ct == k)
                {
                    ct = i+1;
                    break;
                }
            }
        }
        
        return ct;
    }