int countTime(string time) {
        int sum = 0;
        if (time[0] == '?')
        {
            if (time[1] == '?')
                sum = 24;
            else if (time[1] < '4')
                sum = 3;
            else
                sum = 2;
        }
        else
        {
            if (time[1] == '?')
            {
                if (time[0] != '2')
                    sum = 10;
                else
                    sum = 4;
            }
            else
                sum = 1;
        }
        
        if (time[3] == '?')
        {
            if (time[4] == '?')
                sum *= 60;
            else
                sum *= 6;
        }
        else
        {
            if (time[4] == '?')
                sum *= 10;
        }
        
        return sum;
    }