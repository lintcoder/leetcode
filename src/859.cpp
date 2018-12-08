bool buddyStrings(string A, string B) {
        int len1 = A.size();
        int len2 = B.size();
        if (len1 != len2)
            return false;
        if (len1 < 2)
            return false;
        if (A == B)
        {
            array<int, 26> arr = {0};
            if (len1 > 26)
                return true;
            for (int i = 0; i < len1; ++i)
            {
                arr[A[i]-'a']++;
                if (arr[A[i]-'a'] > 1)
                    return true;
            }
            return false;
        }
        char a, b;
        int ct = 0;
        for (int i = 0; i < len1; ++i)
        {
            if (A[i] != B[i])
            {
                if (ct == 0)
                {
                    a = A[i];
                    b = B[i];
                    ++ct; 
                }
                else if (ct == 1)
                {
                    if (a != B[i] || b != A[i])
                        return false;
                    else
                        ++ct;
                }
                else
                    return false;
            }  
        }
        
        return true;
    }