string minimizeResult(string expression) {
        int num1 = 0, num2 = 0;
        int len = expression.size();
        int index = expression.find('+');
        int m = len-1-index;
        for (int i = 0; i < index; ++i)
            num1 = num1*10 + (expression[i]-'0');
        for (int i = index+1; i < len; ++i)
            num2 = num2*10 + (expression[i]-'0');
        
        int digit1[20] = {1,num1}, digit2[20] = {num2,1};
        int n = pow(10, index-1);
        for (int i = 1; i < index; ++i)
        {
            digit1[i*2] = num1/n;
            digit1[i*2+1] = num1%n;
            n /= 10;
        }
        n = 10;
        for (int i = 1; i < m; ++i)
        {
            digit2[i*2] = num2/n;
            digit2[i*2+1] = num2%n;
            n *= 10;
        }
        
        int minval = 1e9;
        int p = 0, q = 0;
        for (int i = 0; i < index; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int val = digit1[i*2]*(digit1[i*2+1] + digit2[j*2])*digit2[j*2+1];
                if (val < minval)
                {
                    minval = val;
                    p = i;
                    q = j;
                }
            }
        }

        string res(len+2, ' ');
        int k = 0;
        for (int i = 0; i < len+2; ++i)
        {
            if (i == p)
                res[i] = '(';
            else if (i == len+1-q)
                res[i] = ')';
            else
                res[i] = expression[k++];
        }
        
        return res;
    }