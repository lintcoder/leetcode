bool uniqueOccurrences(vector<int>& arr) {
        int len = arr.size();
        if (len <= 1)
            return true;
        if (len == 2)
            return arr[0] == arr[1];
        
        char num[1001] = {0};
        sort(arr.begin(), arr.end());
        int i = 1;
        int last = arr[0];
        int ct = 1;
        while (i < len)
        {
            if (arr[i] == last)
                ++ct;
            else
            {
                if (num[ct] == 0)
                {
                    num[ct] = 1;
                    last = arr[i];
                    ct = 1;
                }
                else
                    return false;
            }
            ++i;
        }
        
        return true;
    }