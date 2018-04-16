bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0)
            return true;
        
        int len = flowerbed.size();
        int i = 0;
        if (len == 1)
            return flowerbed[0] == 0;
        
        while (i < len && n > 0)
        {
            if (i == 0)
            {
                if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)
                {
                    n--;
                    i += 2;
                }
                else
                    ++i;
            }
            else if (i < len - 1)
            {
                if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
                {
                    n--;
                    i += 2;
                }
                else
                    ++i;
            }
            else
            {
                if (n == 1)
                    return flowerbed[i - 1] == 0 && flowerbed[i] == 0;
                else
                    return false;
            }
        }
        return n == 0;
    }