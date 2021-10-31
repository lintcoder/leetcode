int getLucky(string s, int k) {
        const int val[26] = {1,2,3,4,5,6,7,8,9,
                            1,2,3,4,5,6,7,8,9,10,
                            2,3,4,5,6,7,8};
        int len = s.size();
        int sum = 0;
        for (int i = 0; i < len; ++i)
        {
            sum += val[s[i]-'a'];
        }
        if (sum < 10)
            return sum;
        
        while (--k)
        {
            int tmp = 0;
            while (sum > 0)
            {
                tmp += sum%10;
                sum /= 10;
            }
            
            sum = tmp;
            if (sum < 10)
                break;
        }
        
        return sum;
    }