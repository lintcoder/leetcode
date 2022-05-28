string removeDigit(string number, char digit) {
        int len = number.size();
        int pos = len;
        for (int i = 0; i < len; ++i)
        {
            if (number[i] == digit)
            {
                pos = i;
                if (i < len-1 && number[i] < number[i+1])
                    break;
            }
        }
        
        string res(len-1, ' ');
        int k = 0;
        for (int i = 0; i < len; ++i)
        {
            if (i != pos)
                res[k++] = number[i];
        }
        
        return res;
    }