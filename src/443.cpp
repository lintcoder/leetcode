int compress(vector<char>& chars) {
        int len = chars.size();
        char c = chars[0];
        int i = 1, j = 0;
        int ct = 1;
        while (i < len)
        {
        	if (chars[i] == c)
        		++ct;
        	else
        	{
        		if (ct > 1)
	        		modify_arr(chars, j, c, ct);
	        	else
	        		chars[j++] = c;
	         c = chars[i];
        		ct = 1;
        	}
        	++i;
        }
        if (ct > 1)
        	modify_arr(chars, j, c, ct);
        else
        	chars[j++] = c;

        return j;
    }

void modify_arr(vector<char>& chars, int& pos, char c, int num)
{
	char digit[4] = {'\0'};
	int i = 0;
	chars[pos++] = c;
	while (num > 0)
	{
		digit[i++] = num%10 + '0';
		num /= 10;
	}
	i = i - 1;
	while (i >= 0)
		chars[pos++] =digit[i--];
}