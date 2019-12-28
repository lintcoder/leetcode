int lastStoneWeight(vector<int>& stones) {
        int sz = stones.size();
        if (sz == 1)
            return stones[0];
        if (sz == 2)
            return abs(stones[0] - stones[1]);
        
        sort(stones.rbegin(), stones.rend());
        int ct = sz;
        int i = 0, j = 0;
        int tmp = 0;
        while (ct > 1)
        {
            tmp = stones[i]-stones[i+1];
            if (tmp == 0)
            {
                ct -= 2;
                i += 2;
            }
            else
            {
                j = i+2;
                int k = ct - 2;
                while (k > 0 && stones[j] > tmp)
                {
                    stones[j-1] = stones[j];
                    --k;
                    ++j;
                }
                stones[j-1] = tmp;
                ct--;
                i++;
            }
        }
        if (ct == 0)
            return 0;
        else
        {
            if (tmp != 0)
                return tmp;
            else
                return stones[i];
        }
    }