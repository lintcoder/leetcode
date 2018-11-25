bool isIsomorphic(string s, string t) {
        map<char, char> dict;
        set<char> st;
        int sz = s.size();
    
        for (int i = 0; i != sz; ++i)
        {
            map<char, char>::iterator miter = dict.find(s[i]);
            set<char>::iterator siter = st.find(t[i]);

            if (miter == dict.end() && siter == st.end())
            {
                dict[s[i]] = t[i];
                st.insert(t[i]);
            }
            else if (miter != dict.end() && siter != st.end())
            {
                if (dict[s[i]] != t[i])
                    return false;
            }
            else
                return false;
        }
    
        return true;
    }