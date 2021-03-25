bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        int len = s1.size();
        int ct = 0;
        char arr[4];
        for (int i = 0; i < len; ++i)
        {
            if (s1[i] != s2[i])
            {
                if (ct == 2)
                    return false;
                arr[ct*2] = s1[i];
                arr[ct*2+1] = s2[i];
                ++ct;
            }
        }
        
        if (ct == 1)
            return false;
        
        if (arr[0] == arr[3] && arr[1] == arr[2])
            return true;
        else
            return false;
    }