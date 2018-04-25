string originalDigits(string s) {
        int letters[26] = {0};
        int len = s.size();
        for (int i = 0; i < len; ++i)
        	letters[s[i] - 'a']++;
        string res;

        if (letters['z' - 'a'] != 0)
        {
        	letters['e' - 'a'] -= letters['z' - 'a'];
        	letters['r' - 'a'] -= letters['z' - 'a'];
        	letters['o' - 'a'] -= letters['z' - 'a'];
        	len -= 4*letters['z' - 'a'];
        	res = string(letters['z' - 'a'], '0');
        	letters['z' - 'a'] = 0;
        }
        if (letters['w' - 'a'] != 0)
        {
        	letters['t' - 'a'] -= letters['w' - 'a'];
        	letters['o' - 'a'] -= letters['w' - 'a'];
        	len -= 3*letters['w' - 'a'];
        	res += string(letters['w' - 'a'], '2');
        	letters['w' - 'a'] = 0;
        }
        if (letters['u' - 'a'] != 0)
        {
        	letters['f' - 'a'] -= letters['u' - 'a'];
        	letters['o' - 'a'] -= letters['u' - 'a'];
        	letters['r' - 'a'] -= letters['u' - 'a'];
        	len -= 4*letters['u' - 'a'];
        	res += string(letters['u' - 'a'], '4');
        	letters['u' - 'a'] = 0;
        }
        if (letters['x' - 'a'] != 0)
        {
        	letters['s' - 'a'] -= letters['x' - 'a'];
        	letters['i' - 'a'] -= letters['x' - 'a'];
        	len -= 3*letters['x' - 'a'];
        	res += string(letters['x' - 'a'], '6');
        	letters['x' - 'a'] = 0;
        }
        if (letters['g' - 'a'] != 0)
        {
        	letters['e' - 'a'] -= letters['g' - 'a'];
        	letters['i' - 'a'] -= letters['g' - 'a'];
        	letters['h' - 'a'] -= letters['g' - 'a'];
        	letters['t' - 'a'] -= letters['g' - 'a'];
        	len -= 5*letters['g' - 'a'];
        	res += string(letters['g' - 'a'], '8');
        	letters['g' - 'a'] = 0;
        }
        if (letters['o' - 'a'] != 0)
        {
        	res += string(letters['o' - 'a'], '1');
        }
        if (letters['t' - 'a'] != 0)
        {
        	res += string(letters['t' - 'a'], '3');
        }
        if (letters['f' - 'a'] != 0)
        {
        	letters['i' - 'a'] -= letters['f' - 'a'];
        	letters['v' - 'a'] -= letters['f' - 'a'];
        	letters['e' - 'a'] -= letters['f' - 'a'];
        	len -= 4*letters['f' - 'a'];
        	res += string(letters['f' - 'a'], '5');
        	letters['f' - 'a'] = 0;
        }
		if (letters['s' - 'a'] != 0)
        {
        	res += string(letters['s' - 'a'], '7');
        }
        if (letters['i' - 'a'] != 0)
        {
        	res += string(letters['i' - 'a'], '9');
        }
        sort(res.begin(), res.end());

        return res;
    }