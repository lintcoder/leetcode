string removeTrailingZeros(string num) {
        int len = num.size();
        int i;
        for (i = len-1; i >= 0; --i)
        {
            if (num[i] != '0')
                break;
        }

        return num.substr(0, i+1);
    }