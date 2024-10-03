string convertDateToBinary(string date) {
        const string sdate[] = {"1", "10", "11", "100", "101", "110", "111",
                                "1000", "1001", "1010", "1011", "1100", "1101", "1110",
                                "1111", "10000", "10001", "10010", "10011", "10100", "10101",
                                "10110", "10111", "11000", "11001", "11010", "11011", "11100",
                                "11101", "11110", "11111"};

        int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
        int month = (date[5]-'0')*10 + (date[6]-'0');
        int day = (date[8]-'0')*10 + (date[9]-'0');

        string sy;
        while (year != 0)
        {
            sy.push_back(year%2 + '0');
            year /= 2;
        }
        reverse(sy.begin(), sy.end());

        stringstream ss;
        ss << sy << '-' << sdate[month-1] << '-' << sdate[day-1];

        return ss.str();
    }