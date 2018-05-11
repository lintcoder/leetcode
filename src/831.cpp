string maskPII(string S) {
        int len = S.size();
        if (isalpha(S[0]))
        {
        	int pos = S.find('@');
        	int n = 7 + len - pos;
        	string res(n, '*');
        	res[0] = tolower(S[0]);
        	res[6] = tolower(S[pos-1]);
        	int j = 7;
        	for (int i = pos; i < len; ++i)
        		if (isalpha(S[i]))
        			res[j++] = tolower(S[i]);
        		else
        			res[j++] = S[i];
        	return res;
        }
        else
        {
        	int i = 0, j = 0;
        	string digit(13, ' ');
        	while (i < len)
        	{
        		if (isdigit(S[i]))
        			digit[j++] = S[i];
        		++i;
        	}
        	if (j == 10)
        		return "***-***-" + digit.substr(j-4, 4);
        	else
        	{
        		string res(14+j-10, '*');
        		res[0] = '+';
        		res[j-10+1] = '-';
        		res[j-10+5] = res[j-1] = '-';
        		res[j] = digit[j-4];
        		res[j+1] = digit[j-3];
        		res[j+2] = digit[j-2];
        		res[j+3] = digit[j-1];
        		return res;
        	}
        }
    }