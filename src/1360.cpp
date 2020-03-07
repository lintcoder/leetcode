int daysBetweenDates(string date1, string date2) {
        
        int mdays[12] = {31,28,31,30,31,30,
                        31,31,30,31,30,31};
        int year1 = atoi(date1.substr(0, 4).c_str());
        int year2 = atoi(date2.substr(0, 4).c_str());
        int month1 = (date1[5]-'0')*10 + (date1[6]-'0');
        int month2 = (date2[5]-'0')*10 + (date2[6]-'0');
        int day1 = (date1[8]-'0')*10 + (date1[9]-'0');
        int day2 = (date2[8]-'0')*10 + (date2[9]-'0');
        
        int interval1 = 0, interval2 = 0;
        for (int i = 1971; i < year1; ++i)
            interval1 += (i-1972)%4 != 0 ? 365 : 366;
        for (int i = 1971; i < year2; ++i)
            interval2 += (i-1972)%4 != 0 ? 365 : 366;
        
        for (int i = 1; i < month1; ++i)
        {
            interval1 += mdays[i-1];
            if (i == 2)
            {
                if ((year1-1972)%4 == 0 && year1 != 2100)
                    interval1 += 1;
            }
        }

        for (int i = 1; i < month2; ++i)
        {
            interval2 += mdays[i-1];
            if (i == 2)
            {
                if ((year2-1972)%4 == 0 && year2 != 2100)
                    interval2 += 1;
            }
        }
        interval1 += day1;
        interval2 += day2;
        
        return abs(interval1-interval2);
    }