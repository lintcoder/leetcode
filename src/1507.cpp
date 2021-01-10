string reformatDate(string date) {
        map<string, string> mp{{"Jan","01"},{"Feb","02"},{"Mar","03"},{"Apr","04"},
                               {"May","05"},{"Jun","06"},{"Jul","07"},{"Aug","08"},
                               {"Sep","09"},{"Oct","10"},{"Nov","11"},{"Dec","12"}};
        int index = date.find(' ');
        stringstream ss;
        ss << *(date.rbegin()+3) << *(date.rbegin()+2) << *(date.rbegin()+1) << *date.rbegin() << '-';
        string month = mp[date.substr(index+1, 3)];
        ss << month << '-';
        if (index == 3)
            ss <<'0';
        ss << date.substr(0, index-2);
        
        return ss.str();
    }