string bestHand(vector<int>& ranks, vector<char>& suits) {
        int nrank[14] = {0};
        char suit = suits[0];
        int n = 0, maxnum = 0;
        
        for (int i = 0; i < 5; ++i)
        {
            if (suits[i] == suit)
                ++n;
            nrank[ranks[i]]++;
            if (maxnum < 2 && nrank[ranks[i]] == 2)
                maxnum = 2;
            else if (nrank[ranks[i]] == 3)
                maxnum = 3;
        }
        
        if (n == 5)
            return "Flush";
        else if (maxnum == 3)
            return "Three of a Kind";
        else if (maxnum == 2)
            return "Pair";
        else
            return "High Card";
    }