int dayOfYear(string date) {
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        
        int num = 0;
        if (date[5] == '0')
            num = date[6]-'0'-1;
        else
            num = date[6]-'0'+9;
        int ct = 0;
        for (int i = 0; i < num; ++i)
            ct += days[i];
        ct += (date[8]-'0')*10 + (date[9]-'0');
        
        int year = atoi(date.substr(0,4).c_str());
        if (num >= 2 && ((year%4 == 0 && year%100 != 0) || year%400 == 0))
            ++ct;
        
        return ct;
    }