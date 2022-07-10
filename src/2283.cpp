bool digitCount(string num) {
        int arr[10] = {0};
        int len = num.size();
        
        for (int i = 0; i < len; ++i)
        {
            arr[num[i]-'0']++;
        }
        
        for (int i = 0; i < len; ++i)
        {
            if (arr[i] != num[i]-'0')
                return false;
        }
        
        return true;
    }