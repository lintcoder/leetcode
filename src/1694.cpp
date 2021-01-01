string reformatNumber(string number) {
        int len = number.size();
        if (len == 2)
            return number;
        
        string str(len, ' ');
        int j = 0;
        for (int i = 0; i < len; ++i)
        {
            if (number[i] != ' ' && number[i] != '-')
                str[j++] = number[i];
        }

        if (j <= 3)
            return str.substr(0, j);
        
        int r = j%3;
        int lim = r == 0 ? j : (r == 1 ? j-4 : j-2);
        int n = 0;
        if (r == 0)
            n = j+j/3-1;
        else if (r == 1)
            n = j-4+(j-4)/3-1+6;
        else
            n = j-2+(j-2)/3-1+3;
            
        string res(n, ' ');
        int i = 0, k = 0;
        while (i < lim)
        {
            res[k++] = str[i++];
            if (k < n && i%3 == 0)
                res[k++] = '-';
        }
        
        if (r == 1)
        {
            res[k] = str[i];
            res[k+1] = str[i+1];
            res[k+2] = '-';
            res[k+3] = str[i+2];
            res[k+4] = str[i+3];
        }
        else if (r == 2)
        {
            res[k] = str[i];
            res[k+1] = str[i+1];
        }
        
        return res;
    }