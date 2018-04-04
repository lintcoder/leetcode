bool judgeCircle(string moves) {
        int right = 0, up = 0;
        int len = moves.size();
        if (len % 2 == 1)
                return false;
        
        for (int i = 0; i < len; ++i)
        {
            if (moves[i] == 'R')
                right++;
            else if (moves[i] == 'L')
                right--;
            else if (moves[i] == 'U')
                up++;
            else
                up--;
        }
        
        return right == 0 && up == 0;
    }