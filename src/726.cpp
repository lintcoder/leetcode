string countOfAtoms(string formula) {
        int len = formula.size();
        if (len <= 1)
        	return formula;

        int i = 0, num = 0;
        string atomic;
        map<string, int> mp;
        while (i < len)
        {
        	if (isalpha(formula[i]))
        	{
        		if (i+1 < len && islower(formula[i+1]))
        		{
        			atomic = formula.substr(i, 2);
        			i += 2;
        		}
        		else
        		{
        			atomic = formula[i];
        			++i;
        		}
        		mp[atomic]++;
        	}
        	else if (isdigit(formula[i]))
        	{
        		auto iter = find_if(formula.begin()+i, formula.end(), not_digit);
        		if (iter == formula.end())
        		{
        			num = stoi(formula.substr(i));
        			mp[atomic] += num-1;
        			break;
        		}
        		else
        		{
        			num = stoi(formula.substr(i, iter-(formula.begin()+i)));
        			mp[atomic] += num-1;
        			i += iter-(formula.begin()+i);
        		}
        	}
        	else if (formula[i] == '(')
        	{
        		map<string, int> submap;
        		++i;
        		countOfGroup(formula, i, submap);
        		++i;
        		if (i < len && isdigit(formula[i]))
        		{
        			auto iter = find_if(formula.begin()+i, formula.end(), not_digit);
        			if (iter == formula.end())
		    			num = stoi(formula.substr(i));
	        		else
	        		{
	        			num = stoi(formula.substr(i, iter-(formula.begin()+i)));
	        			i += iter-(formula.begin()+i);
	        		}
        			for (auto m : submap)
        				mp[m.first] += m.second*num;
        			if (iter == formula.end())
        				break;
        		}
        		else
        		{
        			for (auto m : submap)
        				mp[m.first] += m.second;
        		}
        	}
        }
        num = mp.size();
        vector<string> vec(num, "");
        i = 0;
        for (auto m : mp)
        	vec[i++] = m.first;
        sort(vec.begin(), vec.end());
        string res;
        for (int i = 0; i < num; ++i)
        {
        	res += vec[i];
        	if (mp[vec[i]] > 1)
        		res += to_string(mp[vec[i]]);
        }

        return res;
    }

    static void countOfGroup(const string& formula, int& index, map<string, int>& mp)
    {
        string atomic;
        while (formula[index] != ')')
        {
            if (isalpha(formula[index]))
            {
                if (islower(formula[index+1]))
                {
                    atomic = formula.substr(index, 2);
                    index += 2;
                }
                else
                {
                    atomic = formula[index];
                    ++index;
                }
                mp[atomic]++;
            }
            else if (isdigit(formula[index]))
            {
                auto iter = find_if(formula.begin()+index, formula.end(), not_digit);

                int num = stoi(formula.substr(index, iter-(formula.begin()+index)));
                mp[atomic] += num-1;
                index += iter-(formula.begin()+index);
            }
            else if (formula[index] == '(')
            {
                map<string, int> submap;
                ++index;
                countOfGroup(formula, index, submap);
                ++index;
                if (isdigit(formula[index]))
                {
                    auto iter = find_if(formula.begin()+index, formula.end(), not_digit);
                    int num = stoi(formula.substr(index, iter-(formula.begin()+index)));
                    index += iter-(formula.begin()+index);
                    for (auto m : submap)
                        mp[m.first] += m.second*num;
                }
                else
                {
                    for (auto m : submap)
                        mp[m.first] += m.second;
                }
            }
        }
    }
    
    static bool not_digit(char c)
    {
        return !isdigit(c);
    }