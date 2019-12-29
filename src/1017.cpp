string baseNeg2(int N) {
        if (N <= 1)
            return to_string(N);
        string res;
        while (N != 1)
        {
            if (abs(N)%2 == 0)
            {
                N /= -2;
                res.push_back('0');
            }
            else
            {
                if (N > 0)
                    N = -N/2;
                else
                    N = (-N)/2+1;
                res.push_back('1');
            }
        }
        res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }