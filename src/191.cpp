int hammingWeight(uint32_t n) {
        bitset<32> bt(n);
        int sum = 0;
        for (int i = 0; i < 32; ++i)
            if (bt[i] == 1)
                sum++;
                
        return sum;
    }