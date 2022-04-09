int minBitFlips(int start, int goal) {
        bitset<32> bs(start), bg(goal);
        int ct = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (bs[i] != bg[i])
                ++ct;
        }
        
        return ct;
    }