int countBalls(int lowLimit, int highLimit) {
        int box[50] = {0};
        int i = lowLimit;
        int sum = 0;
        while (i > 0)
        {
            sum += i%10;
            i /= 10;
        }
        box[sum]++;
        
        int last = lowLimit%10;
        i = lowLimit+1;
        while (i <= highLimit)
        {
            if (last < 9)
            {
                sum++;
                box[sum]++;
                ++last;
            }
            else
            {
                sum = 0;
                int t = i;
                while (t > 0)
                {
                    sum += t%10;
                    t /= 10;
                }
                box[sum]++;
                last = i%10;
            }
            ++i;
        }
        
        int maxballs = 0;
        for (int j = 0; j < 50; ++j)
            if (box[j] > maxballs)
                maxballs = box[j];
        
        return maxballs;
    }