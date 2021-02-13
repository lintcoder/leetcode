int maxCoins(vector<int>& piles) {
        int len = piles.size();
        sort(piles.begin(), piles.end());
        int sum = 0;
        int lim = len/3;
        int i = len-2;
        while (i >= 0 && lim > 0)
        {
            sum += piles[i];
            i -= 2;
            --lim;
        }
        
        return sum;
    }