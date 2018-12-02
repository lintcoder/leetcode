bool lemonadeChange(vector<int>& bills) {
        int len = bills.size();
        if (len == 0)
        return true;
        else if (len == 1)
        return bills[0] == 5;

        int change[3] = {0};
        int i = 0;
        while (i < len)
        {
            if (bills[i] == 5)
            ++change[0];
            else if (bills[i] == 10)
            {
                if (change[0] > 0)
                {
                    --change[0];
                    ++change[1];
                }
                else
                return false;
            }
            else
            {
                if (change[0] > 0 && change[1] > 0)
                {
                    --change[0];
                    --change[1];
                    ++change[2];
                }
                else if (change[0] >= 3)
                {
                    change[0] -= 3;
                    ++change[2];
                }
                else
                return false;
            }
            ++i;
        }

        return true;
    }