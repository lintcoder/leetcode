uint32_t reverseBits(uint32_t n) {
        uint32_t sum = 0;
        bitset<32> bt(n);
        for (int i = 0; i < 32; ++i)
            sum = sum * 2 + bt[i];
        return sum;
    }