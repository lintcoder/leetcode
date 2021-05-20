int numDifferentIntegers(string word) {
        int len = word.size();
        for (int i = 0; i < len; ++i)
        {
            if (!isdigit(word[i]))
                word[i] = ' ';
        }
        
        int i = 0;
        int lh = -1, rh = -1;
        set<string> st;
        bool flag = false;
        
        while (i < len)
        {
            if (word[i] == ' ')
                ++i;
            else
            {
                lh = i;
                while (i < len && word[i] == '0')
                    ++i;
                if (i == len)
                {
                    flag = true;
                    break;
                }
                else if (word[i] == ' ')
                    flag = true;
                else
                {
                    lh = i;
                    while (i < len && word[i] != ' ')
                        ++i;
                    st.insert(word.substr(lh, i-lh));
                    if (i == len)
                        break;
                }
            }
        }
        
        if (flag)
            st.insert("0");
        
        return st.size();
    }