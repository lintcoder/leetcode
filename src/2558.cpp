long long pickGifts(vector<int>& gifts, int k) {
        int len = gifts.size();
        long long sum = 0;
        for (int i = 0; i < len; ++i)
            sum += gifts[i];
        
        for (int i = 0; i < k; ++i)
        {
            int index = 0;
            int maxval = 0;
            for (int j = 0; j < len; ++j)
            {
                if (gifts[j] > maxval)
                {
                    index = j;
                    maxval = gifts[j];
                }
            }

            int r = sqrt(maxval);
            if (r == maxval)
                break;
            sum -= gifts[index]-r;
            gifts[index] = r;
        }

        return sum;
    }