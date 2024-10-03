int furthestDistanceFromOrigin(string moves) {
        int nl = 0, nr = 0;
        int len = moves.size();
        for (int i = 0; i < len; ++i)
        {
            if (moves[i] == 'L')
                ++nl;
            if (moves[i] == 'R')
                ++nr;
        }

        return abs(nl-nr) + len-nl-nr;
    }