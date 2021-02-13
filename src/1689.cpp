int minPartitions(string n) {
        int len = n.size();
        char c = '0';
        for (int i = 0; i < len; ++i)
        {
            if (n[i] > c)
                c = n[i];
        }
        
        return c-'0';
    }