int hammingDistance(int x, int y) {
    bitset<32> xbit(x);
    bitset<32> ybit(y);
    int dist = 0;
    for (int i = 0; i < 32; ++i)
        if (xbit[i] != ybit[i])
            ++dist;

    return dist;
}
