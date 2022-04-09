int convertTime(string current, string correct) {
        int curMinutes = ((current[0]-'0')*10+(current[1]-'0'))*60 + ((current[3]-'0')*10+(current[4]-'0'));
        int corrMinutes = ((correct[0]-'0')*10+(correct[1]-'0'))*60 + ((correct[3]-'0')*10+(correct[4]-'0'));
        int delta = corrMinutes - curMinutes;
        int ct = 0;
        if (delta >= 60)
        {
            ct += delta/60;
            delta %= 60;
        }
        if (delta >= 15)
        {
            ct += delta/15;
            delta %= 15;
        }
        if (delta >= 5)
        {
            ct += delta/5;
            delta %= 5;
        }
        
        return ct + delta;
    }