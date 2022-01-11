string capitalizeTitle(string title) {
        int len = title.size();
        int i = 0, pos = 0;
        int n = 0;
        while (i < len)
        {
            if (title[i] != ' ')
            {
                title[i] = tolower(title[i]);
                ++n;
            }
            else
            {
                if (n > 2)
                    title[pos] = toupper(title[pos]);
                n = 0;
                pos = i+1;
            }
            ++i;
        }
        
        if (n > 2)
            title[pos] = toupper(title[pos]);
        
        return title;
    }