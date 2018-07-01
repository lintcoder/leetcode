string toGoatLatin(string S) {
        int len = S.size();
        if (len == 0)
        	return S;

        string res;
        int i = 0, j = 1;
        int pos = 0;
        while ((pos = S.find(' ', i)) != string::npos)
        {
        	string str = S.substr(i, pos-i);
        	if (isvowel(str[0]))
        		res += str + "ma" + string(j, 'a') + ' ';
        	else
        		res += str.substr(1) + str[0] +  "ma" + string(j, 'a') + ' ';
        	++j;
        	i = pos+1;
        }
        string str = S.substr(i);
        if (isvowel(str[0]))
            res += str + "ma" + string(j, 'a');
        else
            res += str.substr(1) + str[0] +  "ma" + string(j, 'a');

        return res;
    }
    
    bool isvowel(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }