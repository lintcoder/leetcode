string decodeString(string s) {
        int len = s.size();
        if (len <= 1)
        	return s;

        int i = 0;
        string res;
        while (i < len)
        {
        	if (isalpha(s[i]))
        	{
        		auto p = find_if(s.begin()+i, s.end(), not_alpha);
        		res.insert(res.end(), s.begin()+i, p);
        		if (p == s.end())
        			break;
        		else
        			i = p-s.begin();
        	}
        	else if (isdigit(s[i]))
        	{
        		auto p = find_if(s.begin()+i, s.end(), not_digit);
        		int n = stoi(s.substr(i, p-(s.begin()+i)));
        		int index = p-s.begin()+1;
        		string ds = decodeSubstring(s, index);
        		for (int i = 0; i < n; ++i)
        			res += ds;
        		i = index+1;
        	}
        }

        return res;
    }

    string decodeSubstring(const string& s, int& pos)
    {
        string res;
        while (s[pos] != ']')
        {
            if (isalpha(s[pos]))
            {
                auto p = find_if(s.begin()+pos, s.end(), not_alpha);
                    res.insert(res.end(), s.begin()+pos, p);
                    pos = p-s.begin();
            }
            else if (isdigit(s[pos]))
                {
                    auto p = find_if(s.begin()+pos, s.end(), not_digit);
                    int n = stoi(s.substr(pos, p-(s.begin()+pos)));
                    int index = p-s.begin()+1;
                    string ds = decodeSubstring(s, index);
                    for (int i = 0; i < n; ++i)
                        res += ds;
                    pos = index+1;
                }
        }
        return res;
    }

    static bool not_alpha(char c)
    {
        return !isalpha(c);
    }

    static bool not_digit(char c)
    {
        return !isdigit(c);
    }