bool isFascinating(int n) {
        if (n > 333)
            return false;
        string s1 = to_string(n);
        string s2 = to_string(n*2);
        string s3 = to_string(n*3);

        int arr[11] = {0}; 
        for (int i = 0; i < 3; ++i)
        {
            arr[s1[i]-'0']++;
            arr[s2[i]-'0']++;
            arr[s3[i]-'0']++;
            if (arr[s1[i]-'0'] > 1 || arr[s2[i]-'0'] > 1 || arr[s3[i]-'0'] > 1
                || s1[i]-'0' == 0 || s2[i]-'0' == 0 || s3[i]-'0' == 0)
                return false;
        }

        return true;
    }