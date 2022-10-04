bool equalFrequency(string word) {
        int len = word.size();
        int arr[26] = {0};
        
        for (int i = 0; i < len; ++i)
        {
            arr[word[i]-'a']++;
        }
        
        int v1 = 0, v2 = 0;
        int n1 = 0, n2 = 0;
        
        for (int i = 0; i < 26; ++i)
        {
            if (arr[i] != 0)
            {
                if (v1 == 0)
                {
                    v1 = arr[i];
                }
                else if (v2 == 0 && v1 != arr[i])
                {
                    v2 = arr[i];
                }
                else if (v2 != 0 && v1 != arr[i] && v2 != arr[i])
                    return false;
            }
        }
        
        if (v1 == 1 && v2 == 0)
            return true;
        
        for (int i = 0; i < 26; ++i)
        {
            if (arr[i] != 0)
            {
                if (arr[i] == v1)
                    ++n1;
                if (arr[i] == v2)
                    ++n2;
            }
        }
        
        if (n2 == 0)
        {
            if (n1 == 1)
                return true;
            else
                return false;
        }
        
        if (n1 != 1 && n2 != 1)
            return false;
        else if (n1 == 1 && n2 != 1)
        {
            if (v1 == 1 || v1-v2 == 1)
                return true;
            else
                return false;
        }
        else if (n1 != 1 && n2 == 1)
        {
            if (v2 == 1 || v2-v1 == 1)
                return true;
            else
                return false;
        }
        else
        {
            if (v1 == 1 || v2 == 1 || abs(v1-v2) == 1)
                return true;
            else
                return false;
        }
    }