int binaryGap(int N) {
        int index[2] = {-1,-1};
        int ct = 0;
        int i = 0, maxdist = 0;
        while (N != 0)
        {
            if (N%2 == 1)
            {
                if (ct < 2)
                {
                    index[ct++] = i;
                }
                else
                {
                    int t = index[1] - index[0];
                    if (t > maxdist)
                        maxdist = t;
                    index[0] = index[1];
                    index[1] = i;
                }
            }
            N /= 2;
            ++i;
        }
        if (ct < 2)
            return 0;
        else
        {
            int t = index[1] - index[0];
            if (t > maxdist)
                maxdist = t;
            return maxdist;
        }
    }