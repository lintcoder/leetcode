string dayOfTheWeek(int day, int month, int year) {
        int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        string dow[7] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
        
        int sum = 0;
        if (year == 1971)
        {
            if (month == 1)
                sum += day;
            else
            {
                for (int i = 0; i < month-1; ++i)
                    sum += month_days[i];
                sum += day;
            }
        }
        else
        {
            for (int i = 1971; i < year; ++i)
            {
                if ((i%4 == 0 && i%100 != 0) || (i%400 == 0))
                    sum += 366;
                else
                    sum += 365;
            }
            for (int i = 0; i < month-1; ++i)
                sum += month_days[i];
            if (((year%4 == 0 && year%100 != 0) || (year%400 == 0)) && (month > 2))
                sum++;
            sum += day;
        }
        
        sum %= 7;
        return dow[sum];
    }