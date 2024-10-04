int minimumChairs(string s) {
        int maxentry = 0, ct = 0;
        for (auto c: s)
        {
            if (c == 'E')
                ++ct;
            else
            {
                if (ct > maxentry)
                {
                    maxentry = ct;
                }
                --ct;
            }
        }

        return maxentry > ct ? maxentry : ct;
    }