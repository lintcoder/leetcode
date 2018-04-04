bool hasAlternatingBits(int n) {
     if (n <= 1)
     return false;
     else
     {
     	int bit = n&0x1;
     	n >>= 1;
     	while (n > 0)
     	{
     		if ((n&0x1) == bit)
     			return false;
     		bit = 1-bit;
     		n >>= 1;
     	}
     	return true;
     }
    }