bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        int i = 0;
        while (i < len - 2)
        {
            if (bits[i] == 0)
                ++i;
            else
                i += 2;
        }
        
        return bits[i] != 1;
    }