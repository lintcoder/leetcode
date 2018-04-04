int findComplement(int num) {
    bitset<32> val(num);
    int i = 31;
    while (i >= 0)
    {
        if (val[i] == 0)
            --i;
        else
            break;
    }
    int sum = 0;
    for (; i >= 0; --i)
    {
        sum = sum * 2 + 1 - val[i];
    }
    return sum;
}
