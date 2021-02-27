bool checkIfCanBreak(string s1, string s2) {
        int len = s1.size();
        if (len == 1)
            return true;
        
        int num[2][26];
        memset(num, 0, 2*26*sizeof(int));
        for (int i = 0; i < len; ++i)
        {
            num[0][s1[i]-'a']++;
            num[1][s2[i]-'a']++;
        }
        
        int i = 25;
        for (; i >= 0; --i)
        {
            if (num[0][i] != num[1][i])
                break;
        }
        if (i <= 0)
            return true;
        if (num[0][i] > num[1][i])
        {
            int j = i;
            int r = num[0][i];
            while (i >= 0 && j >= 0)
            {
                if (r >= num[1][j])
                {
                    r -= num[1][j];
                    --j;
                }
                else
                {
                    --i;
                    for (; i >= j; --i)
                    {
                        r += num[0][i];
                        if (r >= num[1][j])
                            break;
                    }
                    if (i < j)
                        return false;
                }   
            }
            return true;
        }
        else
        {
            int j = i;
            int r = num[1][i];
            while (i >= 0 && j >= 0)
            {
                if (r >= num[0][j])
                {
                    r -= num[0][j];
                    --j;
                }
                else
                {
                    --i;
                    for (; i >= j; --i)
                    {
                        r += num[1][i];
                        if (r >= num[0][j])
                            break;
                    }
                    if (i < j)
                        return false;
                }   
            }
            return true;
        }
    }